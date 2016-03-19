//
//  Damage_PU.hpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 19/03/2016.
//
//

#ifndef Damage_PU_hpp
#define Damage_PU_hpp

#include <stdio.h>
#include "../Pickup.hpp"

class Pickup_Damage: public Pickup{
    
public:
    Pickup_Damage(ofVec2f _pos, float _val);
    
    void collisionResponse(GameObject* other);
};
#endif /* Damage_PU_hpp */
