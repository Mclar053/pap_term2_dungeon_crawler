//
//  Guy.hpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 08/03/2016.
//
//

#ifndef Guy_hpp
#define Guy_hpp

#include <stdio.h>
#include "../Enemy.hpp"

class Enemy_Guy : public Enemy{
    
public:
    Enemy_Guy(ofVec2f _pos = ofVec2f(200,200), float _maxVel = 3);
    
//    void movePattern();
};

#endif /* Guy_hpp */
