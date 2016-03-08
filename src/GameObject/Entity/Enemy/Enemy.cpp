//
//  Enemy.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 08/03/2016.
//
//

#include "Enemy.hpp"

Enemy::Enemy(ofVec2f _pos, float _maxVel):Entity(_pos, _maxVel){
    gameSprite = Sprite("player", 16, 0, 7, 0, 7, 8, 15);
}