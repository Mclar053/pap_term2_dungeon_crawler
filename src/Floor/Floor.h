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
#include "../Room/Room.h"
#include "../Room/SpawnRoom/SpawnRoom.h"
#include "../Room/NormalRoom/NormalRoom.h"
#include "../Room/ShopRoom/ShopRoom.h"
#include "../Room/ItemRoom/ItemRoom.h"

class Floor{
    vector<Room*> rooms;
    vector<vector<int>> grid;
    Floormaker fm;
    int floorNum;
    int currentRoom;
    int spawnRoom;
    
public:
    Floor();
    vector<bool> checkAdjacencies(int _i, int _j);
    void generateFloor();
    void nextFloor();
    Room* getRoom();
    int findSpawn();
    
    vector<vector<int>> getGrid();
    
};

#endif /* defined(__dungeon_crawler__Floor__) */
