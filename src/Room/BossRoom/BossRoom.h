//
//  BossRoom.h
//  dungeon_crawler
//
//  Created by Matthew Clark on 11/02/2016.
//
//

#ifndef __dungeon_crawler__BossRoom__
#define __dungeon_crawler__BossRoom__

#include <stdio.h>

#include "../Room.h"

class BossRoom:public Room{
    
public:
    BossRoom();
    BossRoom(bool _fight, GridPos _fPos, bool _left,bool _up, bool _right, bool _down);
    
    virtual void subGenerateRoom();
};


#endif /* defined(__dungeon_crawler__BossRoom__) */
