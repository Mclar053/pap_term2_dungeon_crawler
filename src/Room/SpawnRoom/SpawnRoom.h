//
//  SpawnRoom.h
//  dungeon_crawler
//
//  Created by Matthew Clark on 29/02/2016.
//
//

#ifndef __dungeon_crawler__SpawnRoom__
#define __dungeon_crawler__SpawnRoom__

#include <stdio.h>

#include "../Room.h"

class SpawnRoom:public Room{
    
public:
    SpawnRoom();
    SpawnRoom(bool _fight, GridPos _fPos, bool _left,bool _up, bool _right, bool _down);
    
    void display();
    
    virtual void subGenerateRoom();
};

#endif /* defined(__dungeon_crawler__SpawnRoom__) */