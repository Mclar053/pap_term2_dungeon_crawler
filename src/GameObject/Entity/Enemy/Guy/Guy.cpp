//
//  Guy.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 08/03/2016.
//
//

#include "Guy.hpp"

Enemy_Guy::Enemy_Guy(ofVec2f _pos, float _maxVel):Enemy(_pos,_maxVel){
    gameSprite = Sprite("player", 16, 0, 7, 0, 7, 8, 15);
}

void Enemy_Guy::movePattern(){
    
}