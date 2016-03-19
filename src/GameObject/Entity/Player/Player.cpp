//
//  Player.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 25/02/2016.
//
//

#include "Player.h"

Player::Player(ofVec2f _pos):Entity(_pos,3,20,45),damage(1),fireRate(30),shotSpeed(5),lastFireFrame(0){
    gameSprite = Sprite("player", 16, 0, 7, 0, 7, 8, 15);
    addHealth(20);
}

bool Player::checkFire(){
    cout<<lastFireFrame<<" "<<fireRate<<" "<<ofGetFrameNum()<<endl;
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
    shotSpeed+=_shotSp;
}

void Player::changeDamage(float _dmg){
    damage+=_dmg;
}

void Player::changeSpeed(float _sp){
    MAX_VEL+=_sp;
}