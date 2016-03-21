//
//  BossRoom.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 11/02/2016.
//
//

#include "BossRoom.h"

BossRoom::BossRoom():Room(true){
    
}

BossRoom::BossRoom(bool _fight, GridPos _fPos, bool _left,bool _up, bool _right, bool _down):Room(_fight,_fPos,_left,_up,_right,_down){
    generateRoom();
    checkOpenDoors();
}

//void BossRoom::display(){
//    for(int i=0; i<grid[0].size(); i++){
//        for(int j=0; j<grid.size(); j++){
//            glPushMatrix();
//            glTranslated(50+i*25,150+j*25, 0);
//            ofPushStyle();
//            ofSetColor(0, 255, 255); //Cyan
//            ofDrawRectangle(0,0,25,25);
//            ofPopStyle();
//            glPopMatrix();
//        }
//    }
//    for(auto _door: doors){
//        _door->display();
//    }
//}

void BossRoom::subGenerateRoom(){
    for(int i=0; i<grid[0].size(); i++){
        for(int j=0; j<grid.size(); j++){
            if(i==floor(grid[0].size()/2) && j==3){
                tiles.push_back(new Trapdoor(ofVec2f(62.5+i*25, 162.5+j*25)));
            }
            else{
                tiles.push_back(new BossFloor(ofVec2f(62.5+i*25, 162.5+j*25)));
            }
        }
    }
    generateEnemies();
}

void BossRoom::generateEnemies(){
    int randomNum = floor(ofRandom(0,3));
    switch (randomNum) {
        case 0:
            enemies.push_back(new Enemy_Guy(ofVec2f(225,400)));
            enemies.push_back(new Enemy_Guy(ofVec2f(325,400)));
            enemies.push_back(new Enemy_Guy(ofVec2f(425,400)));
            enemies.push_back(new Enemy_Guy(ofVec2f(525,400)));
            enemies.push_back(new Enemy_Guy(ofVec2f(625,400)));
            enemies.push_back(new Enemy_Guy(ofVec2f(725,400)));
            enemies.push_back(new Enemy_Guy(ofVec2f(425,200)));
            enemies.push_back(new Enemy_Guy(ofVec2f(425,300)));
            enemies.push_back(new Enemy_Guy(ofVec2f(425,500)));
            break;
        case 1:
            enemies.push_back(new Enemy_Pop(ofVec2f(150,375)));
            enemies.push_back(new Enemy_Pop(ofVec2f(200,375)));
            enemies.push_back(new Enemy_Pop(ofVec2f(300,375)));
            enemies.push_back(new Enemy_Pop(ofVec2f(400,375)));
            enemies.push_back(new Enemy_Pop(ofVec2f(500,375)));
            enemies.push_back(new Enemy_Pop(ofVec2f(600,375)));
            enemies.push_back(new Enemy_Pop(ofVec2f(700,375)));
            enemies.push_back(new Enemy_Pop(ofVec2f(250,375)));
            enemies.push_back(new Enemy_Pop(ofVec2f(350,375)));
            enemies.push_back(new Enemy_Pop(ofVec2f(450,375)));
            enemies.push_back(new Enemy_Pop(ofVec2f(550,375)));
            enemies.push_back(new Enemy_Pop(ofVec2f(650,375)));
            break;
        case 2:
            enemies.push_back(new Enemy_Pop(ofVec2f(150,375)));
            enemies.push_back(new Enemy_Pop(ofVec2f(200,375)));
            enemies.push_back(new Enemy_Pop(ofVec2f(300,375)));
            enemies.push_back(new Enemy_Pop(ofVec2f(400,375)));
            enemies.push_back(new Enemy_Pop(ofVec2f(500,375)));
            enemies.push_back(new Enemy_Pop(ofVec2f(600,375)));
            enemies.push_back(new Enemy_Pop(ofVec2f(700,375)));
            enemies.push_back(new Enemy_Pop(ofVec2f(250,375)));
            enemies.push_back(new Enemy_Pop(ofVec2f(350,375)));
            enemies.push_back(new Enemy_Pop(ofVec2f(450,375)));
            enemies.push_back(new Enemy_Pop(ofVec2f(550,375)));
            enemies.push_back(new Enemy_Pop(ofVec2f(650,375)));
            
            enemies.push_back(new Enemy_Whizz(ofVec2f(150,175)));
            enemies.push_back(new Enemy_Whizz(ofVec2f(200,225)));
            enemies.push_back(new Enemy_Whizz(ofVec2f(300,275)));
            enemies.push_back(new Enemy_Whizz(ofVec2f(400,325)));
            enemies.push_back(new Enemy_Whizz(ofVec2f(500,375)));
            enemies.push_back(new Enemy_Whizz(ofVec2f(600,425)));
            enemies.push_back(new Enemy_Whizz(ofVec2f(700,475)));
            enemies.push_back(new Enemy_Whizz(ofVec2f(250,525)));
            break;
        default:
            break;
    }
}