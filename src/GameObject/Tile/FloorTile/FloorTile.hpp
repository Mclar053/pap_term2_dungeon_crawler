//
//  FloorTile.hpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 03/03/2016.
//
//

#ifndef FloorTile_hpp
#define FloorTile_hpp

#include <stdio.h>
#include "../Tile.hpp"

class FloorTile: public Tile{
    
    
public:
    FloorTile(ofVec2f _pos = ofVec2f(0,0));
};

#endif /* FloorTile_hpp */
