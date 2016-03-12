//
//  ShopRoom.h
//  dungeon_crawler
//
//  Created by Matthew Clark on 11/02/2016.
//
//

#ifndef __dungeon_crawler__ShopRoom__
#define __dungeon_crawler__ShopRoom__

#include <stdio.h>

#include "../Room.h"

class ShopRoom:public Room{
    
public:
    ShopRoom();
    ShopRoom(bool _fight, GridPos _fPos, bool _left,bool _up, bool _right, bool _down);
    void display();
    
    virtual void subGenerateRoom();
};


#endif /* defined(__dungeon_crawler__ShopRoom__) */
