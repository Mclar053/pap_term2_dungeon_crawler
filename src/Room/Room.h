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
#include "../GameObject/Entity/Player/Player.h"
#include "../GameObject/Door/Door.hpp"
#include "../GameObject/Tile/FloorTile/FloorTile.hpp"
#include "../GameObject/Entity/Enemy/Guy/Guy.hpp"

using namespace std;

class Room{
protected:
    int sizeX, sizeY;
    GridPos floorPos;
    vector<vector<int>> grid;
    vector<bool> roomAdjacency;
    vector<Door*> doors;
    vector<Tile*> tiles;
    vector<Entity*> entities;
    
    bool fighting;
    
public:
    Room(bool _fight);
    Room(bool _fight, GridPos _fPos, bool _left,bool _up, bool _right, bool _down);
    
    void generateRoom();
    virtual void subGenerateRoom()=0;
    bool checkEmpty();
    virtual void display();
    
    vector<Door*> getDoors(){
        return doors;
    };
    
    vector<Entity*> getEntities(){
        return entities;
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
