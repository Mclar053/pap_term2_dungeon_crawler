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
    currentRoom = spawnRoom;
}

void Floor::generateFloor(){
    for(int i=0; i<grid[0].size(); i++){
        for(int j=0; j<grid.size(); j++){
            vector<bool> roomAdjacent = checkAdjacencies(i, j);
            switch(grid[j][i]){
                case 3:
                    rooms.push_back(new Room(true,GridPos(j,i),roomAdjacent[0],roomAdjacent[1],roomAdjacent[2],roomAdjacent[3]));
                    break;
                case 4:
                    rooms.push_back(new Room(true,GridPos(j,i),roomAdjacent[0],roomAdjacent[1],roomAdjacent[2],roomAdjacent[3]));
                    break;
                case 9:
                    rooms.push_back(new SpawnRoom(false,GridPos(j,i),roomAdjacent[0],roomAdjacent[1],roomAdjacent[2],roomAdjacent[3]));
                    break;
            }
        }
    }
}

int Floor::findSpawn(){
    for(int i=0; i<rooms.size(); i++){
        if(SpawnRoom* derived = dynamic_cast<SpawnRoom*> (rooms[i])){
            return i;
        }
    }
    return 0;
}

vector<bool> Floor::checkAdjacencies(int _i, int _j){
    vector<bool> _adjacent;
    if(_j-1>=0){
        if(grid[_j-1][_i]!=0) _adjacent.push_back(true); else _adjacent.push_back(false);
    } else _adjacent.push_back(false);
    
    if(_i-1>=0){
        if(grid[_j][_i+1]!=0) _adjacent.push_back(true); else _adjacent.push_back(false);
    } else _adjacent.push_back(false);
        
    if(_j+1<grid.size()){
        if(grid[_j+1][_i]!=0) _adjacent.push_back(true); else _adjacent.push_back(false);
    } else _adjacent.push_back(false);
    
    if(_i+1<grid[0].size()){
        if(grid[_j][_i-1]!=0) _adjacent.push_back(true); else _adjacent.push_back(false);
    } else _adjacent.push_back(false);
    
    return _adjacent;
}

Room* Floor::getRoom(){
    return rooms[currentRoom];
}

vector<vector<int>> Floor::getGrid(){
    return grid;
}