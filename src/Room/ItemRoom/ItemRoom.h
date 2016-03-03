//
//  ItemRoom.h
//  dungeon_crawler
//
//  Created by Matthew Clark on 11/02/2016.
//
//

#ifndef __dungeon_crawler__ItemRoom__
#define __dungeon_crawler__ItemRoom__

#include <stdio.h>

#include "../Room.h"

class ItemRoom:public Room{
    
public:
    ItemRoom();
    ItemRoom(bool _fight, GridPos _fPos, bool _left,bool _up, bool _right, bool _down);
    
    void display();
};


#endif /* defined(__dungeon_crawler__ItemRoom__) */
