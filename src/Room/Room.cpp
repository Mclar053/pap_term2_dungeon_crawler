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
}

Room::Room(bool _fight){
    
}

void Room::display(){
    
    //Display all tiles
    for(auto _tile: tiles){
        glPushMatrix();
        glTranslated(62.5,162.5, 0);
        _tile->display();
        glPopMatrix();
    }
    
    //Display all doors
    for(auto _door: doors){
        _door->display();
    }
    
    //Display all entities
    for(auto _ene: enemies){
        _ene->display();
    }
}

void Room::checkDead(){
    //Reference: Marco Gilles - ShooterInheritence
    // remove all dead objects
    // only do this after the two loops to avoid
    // invalidated iterators
    auto it = std::remove_if(enemies.begin(), enemies.end(),
                             [](Enemy *_ene){
                                 return !_ene->isAlive();
                             });
    for(auto _ene: enemies){
        if(!_ene->isAlive()){
            delete _ene;
            _ene = nullptr;
        }
    }
    enemies.erase(it, enemies.end());
    
    /*
    it = std::remove_if(pickups.begin(), pickups.end(),
                             [](Pickup *_pu){
                                 return !_pu->isAlive();
                             });
    for(auto _pu: pickups){
        if(!_pu->isAlive()){
            delete _pu;
            _pu = nullptr;
        }
    }
    pickups.erase(it, pickups.end());
     */
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
    for(int i=0; i<grid[0].size(); i++){
        for(int j=0; j<grid.size(); j++){
            tiles.push_back(new FloorTile(ofVec2f(i*25, j*25)));
        }
    }
    
    subGenerateRoom();
}

Room::~Room(){
    for(auto _d : doors){
        delete _d;
        _d = nullptr;
    }
    
    for(auto _t : tiles){
        delete _t;
        _t = nullptr;
    }
    
    for(auto _e: enemies){
        delete _e;
        _e = nullptr;
    }
}