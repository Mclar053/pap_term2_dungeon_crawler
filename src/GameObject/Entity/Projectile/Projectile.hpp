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
    
public:
    Projectile(ofVec2f _pos, float _maxVel);
};

#endif /* Projectile_hpp */
