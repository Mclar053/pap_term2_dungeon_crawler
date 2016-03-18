//
//  Pop.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 17/03/2016.
//
//

#include "Pop.hpp"

Enemy_Pop::Enemy_Pop(ofVec2f _pos, float _maxVel):Enemy(_pos,_maxVel,10){
    gameSprite = Sprite("player", 16, 0, 7, 0, 7, 8, 15);
    movementPattern = {{2,30},{0,6},{-1,120},{0,30},{2,6},{-1,120}};
    addHealth(10);
}