//
//  Whizz.hpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 19/03/2016.
//
//

#ifndef Whizz_hpp
#define Whizz_hpp

#include <stdio.h>
#include "../Enemy.hpp"

class Enemy_Whizz : public Enemy{
    
public:
    Enemy_Whizz(ofVec2f _pos = ofVec2f(200,200), float _maxVel = 15);
    
    //    void movePattern();
};

#endif /* Whizz_hpp */
