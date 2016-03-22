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
    vector<Room*> rooms; //Vector of room object pointers
    vector<vector<int>> grid; //Grid of the floor
    Floormaker* fm; //Floormaker object pointer
    int floorNum; //Current floor number
    int currentRoom; //The current room the player is on
    int spawnRoom; //The spawn room
    GridPos currentGridPos; //The current grid position
    
public:
    Floor(int _floorNum=1);
    vector<bool> checkAdjacencies(int _i, int _j); //Checks for room adjacencies
    void generateFloor(); //Generates room objects on the floor
    Room* getRoom(); //Gets the current room the player is on
    int findSpawn(); //Finds the position of the spawn room in the rooms vector
    void moveRoom(GridPos _pos); //Moves the currentGridPos by the grid position that has been passed in
    GridPos findSpawnGridPos(); //Finds the spawn rooms grid position
    
    vector<vector<int>> getGrid(); //Returns the int[][] vector of the grid
    
    //Destructor removes all room pointers
    virtual ~Floor(){
        for(auto _r : rooms){
            delete _r;
            _r = nullptr;
        }
    };
    
};

#endif /* defined(__dungeon_crawler__Floor__) */
