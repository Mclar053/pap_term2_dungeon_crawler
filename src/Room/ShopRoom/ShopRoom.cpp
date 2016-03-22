//
//  ShopRoom.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 11/02/2016.
//
//

//Currently does not differ from Item room

#include "ShopRoom.h"

ShopRoom::ShopRoom():Room(false){
    
}

ShopRoom::ShopRoom(bool _fight, GridPos _fPos, bool _left,bool _up, bool _right, bool _down):Room(_fight,_fPos,_left,_up,_right,_down){
    generateRoom();
    checkOpenDoors();
}

void ShopRoom::subGenerateRoom(){
    //Adds normal floor tiles to cover the floor of the room
    for(int i=0; i<grid[0].size(); i++){
        for(int j=0; j<grid.size(); j++){
            tiles.push_back(new FloorTile(ofVec2f(62.5+i*25, 162.5+j*25)));
        }
    }
}