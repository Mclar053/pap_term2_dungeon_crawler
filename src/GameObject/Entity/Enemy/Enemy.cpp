//
//  Enemy.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 08/03/2016.
//
//

#include "Enemy.hpp"

Enemy::Enemy(ofVec2f _pos, float _maxVel):Entity(_pos, _maxVel){
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