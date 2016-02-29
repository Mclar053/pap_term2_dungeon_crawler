//
//  Room.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 06/02/2016.
//
//

#include "Room.h"

Room::Room(bool _fight, GridPos _fPos, bool _left,bool _up, bool _right, bool _down):fighting(_fight),sizeX(28),sizeY(18),floorPos(_fPos){
    grid.resize(sizeY);
    for(auto &_y: grid) _y.resize(sizeX);
    
    roomAdjacency.push_back(_left);
    roomAdjacency.push_back(_up);
    roomAdjacency.push_back(_right);
    roomAdjacency.push_back(_down);
    
    generateRoom();
}

Room::Room(bool _fight){
    
}

void Room::display(){
    for(int i=0; i<grid[0].size(); i++){
        for(int j=0; j<grid.size(); j++){
            glPushMatrix();
            glTranslated(50+i*25,150+j*25, 0);
            ofPushStyle();
            ofSetColor(255, 0, 0);
            ofDrawRectangle(0,0,25,25);
            ofPopStyle();
            glPopMatrix();
        }
    }
}

void Room::generateRoom(){
    
}