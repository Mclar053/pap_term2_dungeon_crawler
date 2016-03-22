#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //Load music and play on loop
    music.load("music/crawler2.mp3");
    music.setLoop(true);
    music.play();
    
    //Create font object in dynamic memory
    font = new ofTrueTypeFont();
    font->load(OF_TTF_SANS, 18);
    
    //Load all images used in game into the image manager
    loadImages();
    
    //set size of the map grid squares in the top left corner of the game screen
    size = 7;
    gameState = 0; //Set gamestate to main menu
    reset(); //Reset the whole game to start from the beginning
}

//--------------------------------------------------------------
void ofApp::update(){
    switch(gameState){
        case 1:
            //Player movement
            player->move();
            
            //Checks if the player can shoot and if so then create a projectile that moves in the direction that it is being fired in
            if(shootLeft){
                if(player->fire()){
                    Projectile* new_bullet = new Projectile(player->getPos(), player->getShotSpeed(), player->getDamage());
                    bullets.push_back(new_bullet);
                    new_bullet->moveLeft();
                    new_bullet = nullptr;
                }
            }
            if(shootRight){
                if(player->fire()){
                    Projectile* new_bullet = new Projectile(player->getPos(), player->getShotSpeed(),player->getDamage());
                    bullets.push_back(new_bullet);
                    new_bullet->moveRight();
                    new_bullet = nullptr;
                }
            }
            if(shootUp){
                if(player->fire()){
                    Projectile* new_bullet = new Projectile(player->getPos(), player->getShotSpeed(),player->getDamage());
                    bullets.push_back(new_bullet);
                    new_bullet->moveUp();
                    new_bullet = nullptr;
                }
            }
            if(shootDown){
                if(player->fire()){
                    Projectile* new_bullet = new Projectile(player->getPos(), player->getShotSpeed(),player->getDamage());
                    bullets.push_back(new_bullet);
                    new_bullet->moveDown();
                    new_bullet = nullptr;
                }
            }
            
            
            //Gets all the gameobjects from the current room object in dynamic memory
            vector<Door*> doors = currentRoom->getDoors();
            vector<Enemy*> enemies = currentRoom->getEnemies();
            vector<Pickup*> pickups = currentRoom->getPickups();
            vector<Tile*> tiles = currentRoom->getTiles();
            
            //Projectiles being looped through in order to move
            //Projectiles checking if they have hit the edge of the room
            //If so, then they die
            for(auto _proj: bullets){
                _proj->move();
                if(_proj->edgeDetect()){
                    _proj->die();
                }
            }
            
            /*
             -Loops through enemies to move each one and to check if they change their position in their movement pattern.
             -Checks for a player-enemy collision and the enemy has a collision response on the player
             -Checks for projectile-enemy collision and the projectile and the enemy have a collision reponse to each other
             */
            for(auto &_ene: enemies){
                _ene->moveNextPattern();
                _ene->movePattern();
                _ene->move();
                if(_ene->collide(player)){
                    _ene->collisionResponse(player);
                }
                for(auto _proj: bullets){
                    if(_ene->collide(_proj)){
                        _ene->collisionResponse(_proj);
                        _proj->collisionResponse(_ene);
                    }
                }
            }
            
            //Player-Pickup collision
            for(auto &_pu: pickups){
                if(_pu->collide(player)){
                    _pu->collisionResponse(player);
                }
            }
            
            //Checks if the room is empty of enemies
            if(currentRoom->checkEmpty()){
                
                //Player-door collision
                for(auto &_door: doors){
                    if(_door->collideLeft(player)){
                        killBullets();
                        player->setPos(ofVec2f(75,375));
                        floor->moveRoom(GridPos(0,1));
                        currentRoom = floor->getRoom();
                    }
                    if(_door->collideRight(player)){
                        killBullets();
                        player->setPos(ofVec2f(725,375));
                        floor->moveRoom(GridPos(0,-1));
                        currentRoom = floor->getRoom();
                    }
                    if(_door->collideTop(player)){
                        killBullets();
                        player->setPos(ofVec2f(400,175));
                        floor->moveRoom(GridPos(1,0));
                        currentRoom = floor->getRoom();
                    }
                    if(_door->collideBottom(player)){
                        killBullets();
                        player->setPos(ofVec2f(400,575));
                        floor->moveRoom(GridPos(-1,0));
                        currentRoom = floor->getRoom();
                    }
                }
                
                //Checks for player-trapdoor collision
                for(auto &_tile: tiles){
                    Trapdoor* _trapdoor = dynamic_cast<Trapdoor*>(_tile);
                    if(_trapdoor){
                        if(_trapdoor->collide(player)){
                            nextFloor = true;
                        }
                    }
                }
            }
            
            //Check for dead objects
            checkDead();
            currentRoom->checkDead();
            
            //Move to next floor
            if(nextFloor){
                lvl++; //Adds 1 to the floor level
                delete floor; // Delete floor before creating new one to avoid memory leak. Avg memory = ~20MB
                floor = new Floor(lvl); //Creates a new floor
                currentRoom = floor->getRoom(); //Gets the current room
                grid = floor->getGrid(); //Gets the grid for the floor
                nextFloor = false; //Set next floor the false
            }

            break;
    }
//    cout<<currentRoom->getFloorPos().x<<" "<<currentRoom->getFloorPos().y<<endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    switch(gameState){
        case 1: //Main game
            ofBackground(120, 82, 53);
            
            //Display all game objects
            currentRoom->display();
            for(auto _proj: bullets){
                _proj->display();
            }
            player->display();
            
            
            //Draw all player information
            //Background - Black
            ofPushStyle();
                ofSetColor(0);
                ofDrawRectangle(0, 0, ofGetWidth(), 100);
            ofPopStyle();
            
            //Player stats
            ofPushStyle();
                ofSetColor(255);
                font->drawString("Health:", 150, 40);
                font->drawString("Damage: "+to_string(player->getDamage()), 450, 20);
            font->drawString("Fire Rate: "+to_string(100/player->getFireRate()), 450, 40);
            font->drawString("Speed: "+to_string(player->getMaxSpeed()), 450, 60);
            font->drawString("Shot Speed: "+to_string(player->getShotSpeed()), 450, 80);
            font->drawString("Floor: "+to_string(lvl), 150, 70);
            ofPopStyle();
            
            //Player Health bar
            ofPushMatrix();
                ofTranslate(225, 20);
                ofPushStyle();
                ofSetColor(255, 0, 0);
                    ofDrawRectangle(0, 0, 200, 20);
                ofPopStyle();
            
                ofPushStyle();
                    ofSetColor(0, 255, 0);
                    ofDrawRectangle(0, 0, (200*player->getHealth()/player->getMaxHealth()), 20);
                ofPopStyle();
            ofPopMatrix();
            
            //Draws the Floor map to the top left of the screen
            glPushMatrix();
            glTranslated(10, 5, 0);
            for(int i=0; i<grid[0].size(); i++){
                for(int j=0; j<grid.size(); j++){
                    switch (grid[j][i]) {
                        case 0:
                            break;
                        default:
                            ofPushStyle();
                            ofSetColor(0);
                            ofNoFill();
                            ofDrawRectangle(i*size, j*size, size, size);
                            ofPopStyle();
                            
                            ofPushStyle();
                            ofSetColor(255);
                            ofFill();
                            ofDrawRectangle(i*size, j*size, size, size);
                            ofPopStyle();
                            break;
                    }
                }
            }
            glPopMatrix();
            break;
        case 2: //Game Over
            ofBackground(0);
            font->drawString("Game Over", 30, ofGetHeight()/2);
            font->drawString("Press 'Space' to return to Main Menu", 30, ofGetHeight()/2+30);
            break;
        default: //Main menu
            ofBackground(0);
            font->drawString("Dungeon Crawler Game", 30, 20);
            font->drawString("Press 'Space' to start playing", 30, ofGetHeight()-30);
            font->drawString("Controls", 30, 50);
            font->drawString("w: Move up", 30, 80);
            font->drawString("a: Move left", 30, 100);
            font->drawString("s: Move down", 30, 120);
            font->drawString("d: Move right", 30, 140);
            font->drawString("Up Arrow: Shoot up", 30, 160);
            font->drawString("Left Arrow: Shoot left", 30, 180);
            font->drawString("Down Arrow: Shoot down", 30, 200);
            font->drawString("Right Arrow: Shoot right", 30, 220);
            font->drawString("Move through rooms to get to the boss room.", 30, ofGetHeight()/2);
            font->drawString("Enter trap door in the boss room to get to next floor.", 30,ofGetHeight()/2+20);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(gameState){
        case 1://Main game
            //Player movement keys
            if(key=='a'){
                player->moveLeft();
            }
            if(key=='d'){
                player->moveRight();
            }
            if(key=='w'){
                player->moveUp();
            }
            if(key=='s'){
                player->moveDown();
            }
            
            //Only lets the player shoot in 1 direction at any 1 time
            if(!shootLeft && !shootRight && !shootUp && !shootDown){
                if(key==OF_KEY_LEFT){
                    shootLeft = true;
                }
                if(key==OF_KEY_RIGHT){
                    shootRight = true;
                }
                if(key==OF_KEY_UP){
                    shootUp = true;
                }
                if(key==OF_KEY_DOWN){
                    shootDown = true;
                }
            }
            break;
            
        case 2: //Game Over
            if(key==' '){
                gameState = 0; //Return to main menu
            }
            break;
            
        default: //Main menu
            if(key==' '){
                gameState = 1; //Change state to main game
            }
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch(gameState){
        case 1: //Main game
            if(key=='a'){
                player->stopLeft();
            }
            if(key=='d'){
                player->stopRight();
            }
            if(key=='w'){
                player->stopUp();
            }
            if(key=='s'){
                player->stopDown();
            }
            if(key==OF_KEY_LEFT){
                shootLeft = false;
            }
            if(key==OF_KEY_RIGHT){
                shootRight = false;
            }
            if(key==OF_KEY_UP){
                shootUp = false;
            }
            if(key==OF_KEY_DOWN){
                shootDown = false;
            }
            break;
        default: //Any other screen doesn't utilise the keyReleased function
            break;
    }

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

 /*
 * Loads all images in data folder
  Reference: Marco Gillies. Image Manager Program
  https://github.com/marcogillies/ImageManager
 */
 void ofApp::loadImages(){
 
     // clear all of the object
     // and the image manager
     // (deletes all of the pointers)
     ImageManager::get().reset();
     
     // get all of the .png images in the
     // directory
     ofDirectory dir(ofToDataPath("allImages"));
     //only show png files
     dir.allowExt("png");
     //populate the directory object
     dir.listDir();
     
     //go through and add each image to the image manager
     for(int i = 0; i < dir.size(); i++){
         cout<<dir.getPath(i)<<endl;
     ImageManager::get().add(dir.getPath(i));
     }
 };

//Removes all objects that are set to 'Dead'
void ofApp::checkDead(){
    //Reference: Marco Gilles - ShooterInheritence
    //Link: 
    
    //Checks what projectiles are 'Dead' and puts them to the end on the vector
    auto it = std::remove_if(bullets.begin(), bullets.end(),
                             [](Projectile *_proj){
                                 return !_proj->isAlive();
                             });
    //Cycles through all the projectiles and checks if they are 'alive'
    //If not then delete the object in dynamic memory and set the pointer to null
    for(auto _proj: bullets){
        if(!_proj->isAlive()){
            delete _proj;
            _proj = nullptr;
        }
    }
    //Remove all projectiles that are 'dead'
    bullets.erase(it, bullets.end());
    
    //If the player is not alive, set to game over state and reset the whole game
    if(!player->isAlive()){
        gameState = 2;
        reset();
    }
}

//Sets all the bullets to die
void ofApp::killBullets(){
    for(auto _proj: bullets){
        _proj->die();
    }
}

void ofApp::reset(){
    lvl =1;
    player = new Player(ofVec2f(300,300));
    floor = new Floor(lvl);
    currentRoom = floor->getRoom();
    grid = floor->getGrid();
    shootLeft = false;
    shootRight = false;
    shootUp = false;
    shootDown = false;
    nextFloor = false;
}









//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
