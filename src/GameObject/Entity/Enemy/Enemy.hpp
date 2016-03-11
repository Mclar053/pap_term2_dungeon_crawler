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
protected:
    vector<int> movementPattern;
    int currentMove;
    int delay;
    
public:
    Enemy(ofVec2f _pos, float _maxVel);
    
    virtual void movePattern();
};
#endif /* Enemy_hpp */
