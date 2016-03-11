//
//  Enemy.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 08/03/2016.
//
//

#include "Enemy.hpp"

Enemy::Enemy(ofVec2f _pos, float _maxVel):Entity(_pos, _maxVel){
}

void Enemy::movePattern(){
    if(ofGetFrameNum()%delay == 0){
        currentMove++;
        switch (movementPattern[movementPattern.size()%currentMove]) {
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
                
            default:
                reset();
                moveUp();
                break;
        }
    }
}