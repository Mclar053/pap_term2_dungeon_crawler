//
//  Enemy.hpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 08/03/2016.
//
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>
#include "../Entity.h"

class Enemy : public Entity{
    
    
public:
    Enemy(ofVec2f _pos = ofVec2f(200,200), float _maxVel = 3);
};
#endif /* Enemy_hpp */
