//
//  Floor.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 06/02/2016.
//
//

#include "Floor.h"

Floor::Floor():floorNum(1),currentRoom(0),fm(20,20,floorNum){
    
    fm.generateFloor();
    grid = fm.getGrid();
    generateFloor();
    spawnRoom = findSpawn();
}

void Floor::generateFloor(){
    for(int i=0; i<grid[0].size(); i++){
        for(int j=0; j<grid.size(); j++){
            switch(grid[j][i]){
                case 3:
                    rooms.push_back(new Room(true,GridPos(0,0),true,true,true,true));
                    break;
                case 4:
                    rooms.push_back(new Room(true,GridPos(0,0),true,true,true,true));
                    break;
                case 9:
                    currentRoom = rooms.size()-1;
                    rooms.push_back(new Room(false,GridPos(0,0),true,true,true,true));
                    break;
            }
        }
    }
}

int Floor::findSpawn(){
    for(int i=0; i<rooms.size(); i++){
        if()
    }
    return 0;
}

Room* Floor::getRoom(){
    return rooms[currentRoom];
}