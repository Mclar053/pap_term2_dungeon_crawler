//
//  ShotSpeed_PU.hpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 19/03/2016.
//
//

#ifndef ShotSpeed_PU_hpp
#define ShotSpeed_PU_hpp

#include <stdio.h>
#include "../Pickup.hpp"

class Pickup_ShotSpeed: public Pickup{
    
public:
    Pickup_ShotSpeed(ofVec2f _pos, float _val);
    
    void collisionResponse(GameObject* other);
};

#endif /* ShotSpeed_PU_hpp */
