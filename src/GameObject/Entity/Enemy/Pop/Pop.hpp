//
//  Pop.hpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 17/03/2016.
//
//

#ifndef Pop_hpp
#define Pop_hpp

#include <stdio.h>
#include "../Enemy.hpp"

class Enemy_Pop : public Enemy{
    
public:
    Enemy_Pop(ofVec2f _pos = ofVec2f(200,200), float _maxVel = 20);
    
    //    void movePattern();
};

#endif /* Pop_hpp */
