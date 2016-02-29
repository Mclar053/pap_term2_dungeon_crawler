//
//  Room.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 06/02/2016.
//
//

#include "Room.h"

Room::Room(bool _fight, GridPos _fPos ,bool _up,bool _right, bool _down, bool _left):fighting(_fight),sizeX(28),sizeY(18),floorPos(_fPos){
    grid.resize(sizeY);
    for(auto &_y: grid) _y.resize(sizeX);
    
    roomAdjacency.push_back(_up);
    roomAdjacency.push_back(_right);
    roomAdjacency.push_back(_down);
    roomAdjacency.push_back(_left);
    
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
    for(auto _door: doors){
        _door->display();
    }
}

void Room::generateRoom(){
    //Creates rooms clockwise from up to left
    for(int i=0; i<roomAdjacency.size(); i++){
        ofVec2f _pos;
        if(roomAdjacency[i]){
            switch(i){
                case 1:
                    _pos = ofVec2f(775,375);
                    break;
                case 2:
                    _pos = ofVec2f(400,625);
                    break;
                case 3:
                    _pos = ofVec2f(25,375);
                    break;
                default:
                    _pos = ofVec2f(400,125);
                    break;
            }
            doors.push_back(new Door(_pos,i));
        }
    }
}