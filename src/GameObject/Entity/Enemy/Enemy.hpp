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
    //Direction and delay per move
    vector<vector<int>> movementPattern;
    //Current move in movement pattern
    int currentMove;
    
    //Holds the last frame the enemy changed direction
    int lastFrame;
    
public:
    Enemy(ofVec2f _pos, float _maxVel,float _maxHealth);
    
    virtual void movePattern();
    virtual void moveNextPattern();
    
    virtual void collisionResponse(GameObject* other);
};
#endif /* Enemy_hpp */
