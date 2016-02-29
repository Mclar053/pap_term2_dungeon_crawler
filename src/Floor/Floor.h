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
#include "../Room/Room.h"

class Floor{
    vector<Room*> rooms;
    vector<vector<int>> grid;
    Floormaker fm;
    int floorNum;
    
public:
    Floor();
    
    void generateFloor();
    void nextFloor();
    
};

#endif /* defined(__dungeon_crawler__Floor__) */
