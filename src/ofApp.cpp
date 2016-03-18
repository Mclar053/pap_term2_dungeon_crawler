#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font = new ofTrueTypeFont();
    font->load(OF_TTF_SANS, 18);
    loadImages();
    lvl =1;
    player = new Player(ofVec2f(300,300));
    floor = new Floor(lvl);
    currentRoom = floor->getRoom();
    grid = floor->getGrid();
    size = 10;
    shootLeft = false;
    shootRight = false;
    shootUp = false;
    shootDown = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    player->move();
    
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
            cout<<player->getShotSpeed()<<endl;
            bullets.push_back(new_bullet);
            new_bullet->moveDown();
            new_bullet = nullptr;
        }
    }
    
    
    vector<Door*> doors = currentRoom->getDoors();
    vector<Enemy*> enemies = currentRoom->getEnemies();
    for(auto _proj: bullets){
        _proj->move();
    }
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
    
    
    for(auto &_door: doors){
        if(_door->collideLeft(player)){
            killBullets();
            player->setPos(ofVec2f(75,375));
            floor->moveRoom(GridPos(0,1));
            currentRoom = floor->getRoom();
            cout<<"left"<<endl;
        }
        if(_door->collideRight(player)){
            killBullets();
            player->setPos(ofVec2f(725,375));
            floor->moveRoom(GridPos(0,-1));
            currentRoom = floor->getRoom();
            cout<<"right"<<endl;
        }
        if(_door->collideTop(player)){
            killBullets();
            player->setPos(ofVec2f(400,175));
            floor->moveRoom(GridPos(1,0));
            currentRoom = floor->getRoom();
            cout<<"top"<<endl;
        }
        if(_door->collideBottom(player)){
            killBullets();
            player->setPos(ofVec2f(400,575));
            floor->moveRoom(GridPos(-1,0));
            currentRoom = floor->getRoom();
            cout<<"bottom"<<endl;
        }
    }
    
    checkDead();
    currentRoom->checkDead();
//    cout<<currentRoom->getFloorPos().x<<" "<<currentRoom->getFloorPos().y<<endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(120, 82, 53);
    currentRoom->display();
    for(auto _proj: bullets){
        _proj->display();
    }
    player->display();
    ofPushStyle();
        ofSetColor(255);
        font->drawString("Health:", 150, 40);
    ofPopStyle();
    
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
    cout<<200*player->getHealth()/player->getMaxHealth()<<endl;
    
    glPushMatrix();
    glTranslated(20, 20, 0);
    for(int i=0; i<grid[0].size(); i++){
        for(int j=0; j<grid.size(); j++){
            switch (grid[j][i]) {
                case 0:
                    break;
                case 9:
                    ofPushStyle();
                    ofSetColor(0);
                    ofNoFill();
                    ofDrawRectangle(i*size, j*size, size, size);
                    ofPopStyle();
                    
                    ofPushStyle();
                    ofSetColor(255, 0, 0);
                    ofFill();
                    ofDrawRectangle(i*size, j*size, size, size);
                    ofPopStyle();
                    
                    
                    break;
                case 4:
                    ofPushStyle();
                    ofSetColor(0);
                    ofNoFill();
                    ofDrawRectangle(i*size, j*size, size, size);
                    ofPopStyle();
                    
                    ofPushStyle();
                    ofSetColor(255, 0, 255);
                    ofFill();
                    ofDrawRectangle(i*size, j*size, size, size);
                    ofPopStyle();
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
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
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
    if(key=='.'){
        lvl++;
        delete floor; // Delete floor before creating new one to avoid memory leak. Avg memory = ~20MB
        floor = new Floor(lvl);
        currentRoom = floor->getRoom();
        grid = floor->getGrid();
    }
    if(key==','){
        lvl--;
        delete floor; // Delete floor before creating new one to avoid memory leak. Avg memory = ~20MB
        floor = new Floor(lvl);
        currentRoom = floor->getRoom();
        grid = floor->getGrid();
    }
    if(key=='l'){
        currentRoom->checkDead();
    }
//    cout<<lvl<<endl;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
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

void ofApp::checkDead(){
    //Reference: Marco Gilles - ShooterInheritence
    // remove all dead objects
    // only do this after the two loops to avoid
    // invalidated iterators
    auto it = std::remove_if(bullets.begin(), bullets.end(),
                             [](Projectile *_proj){
                                 return !_proj->isAlive();
                             });
    for(auto _proj: bullets){
        if(!_proj->isAlive()){
            delete _proj;
            _proj = nullptr;
        }
    }
    bullets.erase(it, bullets.end());
}

void ofApp::killBullets(){
    for(auto _proj: bullets){
        _proj->die();
    }
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
