//
//  Floor.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 06/02/2016.
//
//

#include "Floor.h"

Floor::Floor():floorNum(1),fm(20,20,floorNum){
    
    fm.generateFloor();
    grid = fm.getGrid();
}

void Floor::generateFloor(){
    for(int i=0; i<grid[0].size(); i++){
        for(int j=0; j<grid.size(); j++){
            switch(grid[j][i]){
                case 1:
                    rooms.push_back(new Room(true));
                    break;
                case 4:
                    rooms.push_back(new Room(true));
                    break;
            }
        }
    }
}