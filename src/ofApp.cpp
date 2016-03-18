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
}

//--------------------------------------------------------------
void ofApp::update(){
    player->move();
    vector<Door*> doors = currentRoom->getDoors();
    vector<Enemy*> enemies = currentRoom->getEnemies();
    for(auto &_ene: enemies){
        _ene->moveNextPattern();
        _ene->movePattern();
        _ene->move();
//        _ene->takeDamage(0.1);
        if(_ene->collide(player)){
            _ene->collisionResponse(player);
        }
    }
    
    
    for(auto &_door: doors){
        if(_door->collideLeft(player)){
            player->setPos(ofVec2f(150,375));
            floor->moveRoom(GridPos(0,1));
            currentRoom = floor->getRoom();
            cout<<"left"<<endl;
        }
        if(_door->collideRight(player)){
            player->setPos(ofVec2f(650,375));
            floor->moveRoom(GridPos(0,-1));
            currentRoom = floor->getRoom();
            cout<<"right"<<endl;
        }
        if(_door->collideTop(player)){
            player->setPos(ofVec2f(400,250));
            floor->moveRoom(GridPos(1,0));
            currentRoom = floor->getRoom();
            cout<<"top"<<endl;
        }
        if(_door->collideBottom(player)){
            player->setPos(ofVec2f(400,550));
            floor->moveRoom(GridPos(-1,0));
            currentRoom = floor->getRoom();
            cout<<"bottom"<<endl;
        }
    }
    
    currentRoom->checkDead();
//    cout<<currentRoom->getFloorPos().x<<" "<<currentRoom->getFloorPos().y<<endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    currentRoom->display();
    player->display();
    ofPushStyle();
    ofSetColor(255);
    font->drawString(to_string(player->getHealth()), ofGetWidth()/2, 40);
    ofPopStyle();
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
    if(key==OF_KEY_LEFT){
        player->moveLeft();
    }
    if(key==OF_KEY_RIGHT){
        player->moveRight();
    }
    if(key==OF_KEY_UP){
        player->moveUp();
    }
    if(key==OF_KEY_DOWN){
        player->moveDown();
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
    if(key==OF_KEY_LEFT){
        player->stopLeft();
    }
    if(key==OF_KEY_RIGHT){
        player->stopRight();
    }
    if(key==OF_KEY_UP){
        player->stopUp();
    }
    if(key==OF_KEY_DOWN){
        player->stopDown();
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
