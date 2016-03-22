//
//  Player.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 25/02/2016.
//
//

#include "Player.h"
/*
 Player has default stats of:
 -Damage: 3
 -Firerate: 25 (4 on screen display)
 -Speed: 3
 -Shot speed: 5
 -HP: 20
 */
Player::Player(ofVec2f _pos):Entity(_pos,3,20,45),damage(3),fireRate(25),shotSpeed(5),lastFireFrame(0){
    gameSprite = Sprite("player", 16, 0, 7, 0, 7, 8, 15);
    addHealth(20);
}

//Checks if the last frame the player as fired at + the firerate of the player is less than the current frame number
bool Player::checkFire(){
    if(lastFireFrame+fireRate<ofGetFrameNum()){
        return true;
    }
    return false;
}

//Checks if the player is able to fire and sets the lastfire frame to the current
bool Player::fire(){
    if(checkFire()){
        lastFireFrame = ofGetFrameNum();
        return true;
    }
    return false;
}

//Changes the fire rate of the player
void Player::changeFireRate(float _fr){
    fireRate-=_fr; //Negative as lower the fireRate variable, the faster the reload time is
}

//Changes the shot speed of the player
void Player::changeShotSpeed(float _shotSp){
    if(shotSpeed+_shotSp>0.5)
        shotSpeed+=_shotSp;
}

//Changes the damage of the player
void Player::changeDamage(float _dmg){
    if(damage+_dmg>1)
        damage+=_dmg;
}

//Changes the speed of the player
void Player::changeSpeed(float _sp){
    if(MAX_VEL+_sp>0.5)
        MAX_VEL+=_sp;
}