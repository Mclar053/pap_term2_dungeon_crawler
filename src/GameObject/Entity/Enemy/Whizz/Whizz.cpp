//
//  Whizz.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 19/03/2016.
//
//

#include "Whizz.hpp"

Enemy_Whizz::Enemy_Whizz(ofVec2f _pos, float _maxVel):Enemy(_pos,_maxVel,10){
    gameSprite = Sprite("player", 16, 0, 7, 0, 7, 8, 15);
    movementPattern = {{1,60},{3,6},{-1,120},{3,60},{1,6},{-1,120}};
    addHealth(10);
}