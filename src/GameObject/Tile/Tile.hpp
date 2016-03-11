//
//  Tile.hpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 03/03/2016.
//
//

#ifndef Tile_hpp
#define Tile_hpp

#include <stdio.h>
#include "../GameObject.h"

class Tile: public GameObject{
    
    
public:
    Tile(ofVec2f _pos);
    virtual void subDisplay();
};

#endif /* Tile_hpp */
