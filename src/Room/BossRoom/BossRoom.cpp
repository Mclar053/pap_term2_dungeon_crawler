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
}