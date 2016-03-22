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

//Checks what move the enemy has to take in the pattern
void Enemy::movePattern(){
    switch (movementPattern[currentMove][0]) {
        case 1://Move right
            reset();
            moveRight();
            break;
            
        case 2://Move down
            reset();
            moveDown();
            break;
            
        case 3://Move left
            reset();
            moveLeft();
            break;
            
        case 0://Move up
            reset();
            moveUp();
            break;
            
        default://Do not move
            reset();
            break;
    }
}

//Checks if the current frame number is greater than the last frame + the number of frame for the current move takes
void Enemy::moveNextPattern(){
    if(ofGetFrameNum()>lastFrame+movementPattern[currentMove][1]){
        lastFrame = ofGetFrameNum();
        currentMove+=1; //Change the current move +1
        currentMove = currentMove%movementPattern.size(); //Makes the current move between 0-movementPattern.size()
    }
}

void Enemy::collisionResponse(GameObject* other){
    //Checks for player object
    Player* player = dynamic_cast<Player*>(other);
    if(player){
        player->takeDamage(1);//Remove 1 hp to the player
    }
}