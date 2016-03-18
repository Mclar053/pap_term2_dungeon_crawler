//
//  Projectile.hpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 18/03/2016.
//
//

#ifndef Projectile_hpp
#define Projectile_hpp

#include <stdio.h>
#include "../Entity.h"

class Projectile: public Entity{
    float damage;
    
public:
    Projectile(ofVec2f _pos, float _maxVel, float _damage = 1);
    
    void collisionResponse(GameObject* other);
};

#endif /* Projectile_hpp */
