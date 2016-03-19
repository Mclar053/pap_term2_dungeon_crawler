//
//  TrapDoor.hpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 19/03/2016.
//
//

#ifndef TrapDoor_hpp
#define TrapDoor_hpp

#include <stdio.h>
#include "../Tile.hpp"

class Trapdoor: public Tile{
    
public:
    Trapdoor(ofVec2f _pos = ofVec2f(0,0));
};

#endif /* TrapDoor_hpp */
