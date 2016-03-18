//
//  Enemy.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 08/03/2016.
//
//

#include "Enemy.hpp"
#include "../Player/Player.h"

Enemy::Enemy(ofVec2f _pos, float _maxVel, float _maxHealth):Entity(_pos, _maxVel, _maxHealth){
    lastFrame = 0;
    currentMove = 0;
}

void Enemy::movePattern(){
    switch (movementPattern[currentMove][0]) {
        case 1:
            reset();
            moveRight();
            break;
            
        case 2:
            reset();
            moveDown();
            break;
            
        case 3:
            reset();
            moveLeft();
            break;
            
        case 0:
            reset();
            moveUp();
            break;
            
        default:
            reset();
            break;
    }
}

void Enemy::moveNextPattern(){
    if(ofGetFrameNum()>lastFrame+movementPattern[currentMove][1]){
        lastFrame = ofGetFrameNum();
        currentMove+=1;
        currentMove = currentMove%movementPattern.size();
    }
}

void Enemy::collisionResponse(GameObject* other){
    Player* player = dynamic_cast<Player*>(other);
    if(player){
        player->takeDamage(1);
        this->takeDamage(1);
    }
}