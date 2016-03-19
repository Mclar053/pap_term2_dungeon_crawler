//
//  SpawnFloor.hpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 19/03/2016.
//
//

#ifndef SpawnFloor_hpp
#define SpawnFloor_hpp

#include <stdio.h>
#include "../Tile.hpp"

class SpawnFloor: public Tile{
    
    
public:
    SpawnFloor(ofVec2f _pos = ofVec2f(0,0));
};
#endif /* SpawnFloor_hpp */
