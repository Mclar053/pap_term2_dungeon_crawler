//
//  Player.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 25/02/2016.
//
//

#include "Player.h"
//1,30,5,0
Player::Player(ofVec2f _pos):Entity(_pos,3,20,45),damage(20),fireRate(1),shotSpeed(5),lastFireFrame(0){
    gameSprite = Sprite("player", 16, 0, 7, 0, 7, 8, 15);
    addHealth(20);
}

bool Player::checkFire(){
    if(lastFireFrame+fireRate<ofGetFrameNum()){
        return true;
    }
    return false;
}

bool Player::fire(){
    if(checkFire()){
        lastFireFrame = ofGetFrameNum();
        return true;
    }
    return false;
}

void Player::changeFireRate(float _fr){
    fireRate-=_fr; //Negative as lower the fireRate variable, the faster the reload time is
}

void Player::changeShotSpeed(float _shotSp){
    if(shotSpeed+_shotSp>0.5)
        shotSpeed+=_shotSp;
}

void Player::changeDamage(float _dmg){
    if(damage+_dmg>1)
        damage+=_dmg;
}

void Player::changeSpeed(float _sp){
    if(MAX_VEL+_sp>0.5)
        MAX_VEL+=_sp;
}