//
//  Room.h
//  dungeon_crawler
//
//  Created by Matthew Clark on 06/02/2016.
//
//

#ifndef __dungeon_crawler__Room__
#define __dungeon_crawler__Room__

#include <stdio.h>
#include <vector>

//#include "Enemy.h"
#include "GridPos.h"
#include "ofMain.h"
//Tiles
#include "../GameObject/Tile/FloorTile/FloorTile.hpp"
#include "../GameObject/Tile/BossFloor/BossFloor.hpp"
#include "../GameObject/Tile/Trapdoor/TrapDoor.hpp"
#include "../GameObject/Tile/SpawnFloor/SpawnFloor.hpp"

//Gameobjects
#include "../GameObject/Entity/Player/Player.h"
#include "../GameObject/Door/Door.hpp"
//Enemies
#include "../GameObject/Entity/Enemy/Guy/Guy.hpp"
#include "../GameObject/Entity/Enemy/Pop/Pop.hpp"
#include "../GameObject/Entity/Enemy/Whizz/Whizz.hpp"
//Pickups
#include "../GameObject/Entity/Pickup/Health/Health_PU.hpp"
#include "../GameObject/Entity/Pickup/Speed/Speed_PU.hpp"
#include "../GameObject/Entity/Pickup/ShotSpeed/ShotSpeed_PU.hpp"
#include "../GameObject/Entity/Pickup/Damage/Damage_PU.hpp"
#include "../GameObject/Entity/Pickup/FireRate/FireRate_PU.hpp"

using namespace std;

class Room{
protected:
    int sizeX, sizeY;//Size of the room (28,18)
    vector<vector<int>> grid;
    GridPos floorPos; //Position of where the room is on the floor
    vector<bool> roomAdjacency; //Vector of booleans which describes where to generate doors based on what rooms are next to the current room
    vector<Door*> doors; //Vector of door object pointers
    vector<Tile*> tiles; //Vector of tile object pointers
    vector<Enemy*> enemies; //Vector of enemy object pointers
    vector<Pickup*> pickups; //Vector of pickup object pointers
    
    void addRandomPickup(Enemy* _ene); //Adds random pickup from the position of where the enemy died
    void checkOpenDoors(); //Checks if the doors should look open
    virtual void generateEnemies(); //Generates enemies
    
public:
    Room(bool _fight, GridPos _fPos, bool _left,bool _up, bool _right, bool _down);
    
    void generateRoom(); //Generates the room
    virtual void subGenerateRoom()=0; //Pure Virtual Function used to allow other room types to generate their own type of room. E.g. Boss room and Normal Room
    bool checkEmpty(); //Checks if all enemies in the room have died
    virtual void display(); //Displays the room
    
    void checkDead(); //Checks if any gameobjects are dead and removes them from their respectibe vectors
    
    vector<Door*> getDoors(){ //Returns the vector of door objects pointers
        return doors;
    };
    
    vector<Enemy*> getEnemies(){ //Returns the vector of enemy objects pointers
        return enemies;
    };
    
    vector<Pickup*> getPickups(){ //Returns the vector of pickup objects pointers
        return pickups;
    };
    
    vector<Tile*> getTiles(){ //Returns the vector of tile objects pointers
        return tiles;
    };
    
    GridPos getFloorPos(){ //Returns the position of where on the floor the room is
        return floorPos;
    };
    
    vector<bool> getA(){ //Returns the roomAdjacency vector
        return roomAdjacency;
    };
    
    ofVec2f getSize(){ //Returns the size of the room
        return ofVec2f(700,450);
    }
    
    
    //Removes all doors, tiles and pickups when object is deleted
    virtual ~Room();
    
};

#endif /* defined(__dungeon_crawler__Room__) */
