//
//  NormalRoom.h
//  dungeon_crawler
//
//  Created by Matthew Clark on 11/02/2016.
//
//

#ifndef __dungeon_crawler__NormalRoom__
#define __dungeon_crawler__NormalRoom__

#include <stdio.h>
#include "../Room.h"

class NormalRoom:public Room{
    
public:
    NormalRoom();
    NormalRoom(bool _fight, GridPos _fPos, bool _left,bool _up, bool _right, bool _down);
    
    virtual void subGenerateRoom();
};

#endif /* defined(__dungeon_crawler__NormalRoom__) */
