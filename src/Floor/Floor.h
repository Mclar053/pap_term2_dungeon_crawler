//
//  Floor.h
//  dungeon_crawler
//
//  Created by Matthew Clark on 06/02/2016.
//
//

#ifndef __dungeon_crawler__Floor__
#define __dungeon_crawler__Floor__

#include <stdio.h>

#include "../Floormaker.h"
#include "../Room/SpawnRoom/SpawnRoom.h"
#include "../Room/NormalRoom/NormalRoom.h"
#include "../Room/ShopRoom/ShopRoom.h"
#include "../Room/ItemRoom/ItemRoom.h"
#include "../Room/BossRoom/BossRoom.h"

class Floor{
    vector<Room*> rooms;
    vector<vector<int>> grid;
    Floormaker* fm;
    int floorNum;
    int currentRoom;
    int spawnRoom;
    GridPos currentGridPos;
    
public:
    Floor(int _floorNum=1);
    vector<bool> checkAdjacencies(int _i, int _j);
    void generateFloor();
    void nextFloor();
    Room* getRoom();
    int findSpawn();
    void moveRoom(GridPos _pos);
    GridPos findSpawnGridPos();
    
    vector<vector<int>> getGrid();
    
    //Destructor removes all room pointers
    virtual ~Floor(){
        for(auto _r : rooms){
            delete _r;
            _r = nullptr;
        }
    };
    
};

#endif /* defined(__dungeon_crawler__Floor__) */
