//
//  Health_PU.hpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 19/03/2016.
//
//

#ifndef Health_PU_hpp
#define Health_PU_hpp

#include <stdio.h>
#include "../Pickup.hpp"

class Pickup_Health: public Pickup{
    
public:
    Pickup_Health(ofVec2f _pos, float _val);
    
    void collisionResponse(GameObject* other);
};
#endif /* Health_PU_hpp */
