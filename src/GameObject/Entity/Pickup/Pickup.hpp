//
//  Pickup.hpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 18/03/2016.
//
//

#ifndef Pickup_hpp
#define Pickup_hpp

#include <stdio.h>
#include "../Entity.h"

class Pickup: public Entity{
    float value; //Value to affect player
public:
    Pickup(ofVec2f _pos, float _val);
    
    float getValue(){
        return value;
    }
};

#endif /* Pickup_hpp */
