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

using namespace std;

class Room{
protected:
    int sizeX, sizeY;
    GridPos floorPos;
    vector<vector<int>> grid;
    vector<bool> roomAdjacency;
    vector<Door*> doors;
//    vector<Enemy> entities;
    
    bool fighting;
    
public:
    Room(bool _fight);
    Room(bool _fight, GridPos _fPos, bool _left,bool _up, bool _right, bool _down);
    
    void generateRoom();
    bool checkEmpty();
    virtual void display();
    void playerDoorCollision(Player& _player);
    vector<Door*> getDoors();
    GridPos getFloorPos();
    
    vector<bool> getA();
    
    virtual ~Room(){};
    
};

#endif /* defined(__dungeon_crawler__Room__) */
