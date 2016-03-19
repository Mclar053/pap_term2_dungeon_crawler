//
//  BossFloor.hpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 19/03/2016.
//
//

#ifndef BossFloor_hpp
#define BossFloor_hpp

#include <stdio.h>
#include "../Tile.hpp"

class BossFloor: public Tile{
    
    
public:
    BossFloor(ofVec2f _pos = ofVec2f(0,0));
};

#endif /* BossFloor_hpp */
