//
//  SpawnRoom.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 29/02/2016.
//
//

#include "SpawnRoom.h"

SpawnRoom::SpawnRoom():Room(false){
    
}

SpawnRoom::SpawnRoom(bool _fight, GridPos _fPos, bool _left,bool _up, bool _right, bool _down):Room(_fight,_fPos,_left,_up,_right,_down){
    
}

void SpawnRoom::display(){
    for(int i=0; i<grid[0].size(); i++){
        for(int j=0; j<grid.size(); j++){
            glPushMatrix();
            glTranslated(50+i*25,150+j*25, 0);
            ofPushStyle();
            ofSetColor(0, 255, 0);
            ofDrawRectangle(0,0,25,25);
            ofPopStyle();
            glPopMatrix();
        }
    }
    for(auto _door: doors){
        _door->display();
    }
}