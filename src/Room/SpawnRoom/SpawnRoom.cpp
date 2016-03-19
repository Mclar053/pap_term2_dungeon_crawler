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

SpawnRoom::SpawnRoom(bool _fight, GridPos _fPos, bool _left,bool _up, bool _right, bool _down):Room(false,_fPos,_left,_up,_right,_down){
    generateRoom();
    checkOpenDoors();
}

void SpawnRoom::subGenerateRoom(){
    for(int i=0; i<grid[0].size(); i++){
        for(int j=0; j<grid.size(); j++){
            tiles.push_back(new SpawnFloor(ofVec2f(62.5+i*25, 162.5+j*25)));
        }
    }
}