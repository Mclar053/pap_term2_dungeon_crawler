//
//  FireRate_PU.hpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 19/03/2016.
//
//

#ifndef FireRate_PU_hpp
#define FireRate_PU_hpp

#include <stdio.h>
#include "../Pickup.hpp"

class Pickup_FireRate: public Pickup{
    
public:
    Pickup_FireRate(ofVec2f _pos, float _val);
    
    void collisionResponse(GameObject* other);
};
#endif /* FireRate_PU_hpp */
