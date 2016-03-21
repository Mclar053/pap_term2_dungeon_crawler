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
    int sizeX, sizeY;
    GridPos floorPos;
    vector<vector<int>> grid;
    vector<bool> roomAdjacency;
    vector<Door*> doors;
    vector<Tile*> tiles;
    vector<Enemy*> enemies;
    vector<Pickup*> pickups;
    
    bool fighting;
    
    void addRandomPickup(Enemy* _ene);
    void checkOpenDoors(); //Checks if the doors should look open
    virtual void generateEnemies();
    
public:
    Room(bool _fight);
    Room(bool _fight, GridPos _fPos, bool _left,bool _up, bool _right, bool _down);
    
    void generateRoom();
    virtual void subGenerateRoom()=0;
    bool checkEmpty();
    virtual void display();
    
    void checkDead(); //Checks if any gameobjects are dead and removes them from their respectibe vectors
    
    vector<Door*> getDoors(){
        return doors;
    };
    
    vector<Enemy*> getEnemies(){
        return enemies;
    };
    
    vector<Pickup*> getPickups(){
        return pickups;
    };
    
    vector<Tile*> getTiles(){
        return tiles;
    };
    
    GridPos getFloorPos(){
        return floorPos;
    };
    
    vector<bool> getA(){
        return roomAdjacency;
    };
    
    ofVec2f getSize(){
        return ofVec2f(700,450);
    }
    
    
    //Removes all doors and tiles when object is deleted
    virtual ~Room();
    
};

#endif /* defined(__dungeon_crawler__Room__) */
