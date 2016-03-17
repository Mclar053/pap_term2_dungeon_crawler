//
//  Player.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 25/02/2016.
//
//

#include "Player.h"

Player::Player():Entity(ofVec2f(200,200),3,45){
    gameSprite = Sprite("player", 16, 0, 7, 0, 7, 8, 15);
    addHealth(20);
}

Player::Player(ofVec2f _pos):Entity(_pos,3,45){
    gameSprite = Sprite("player", 16, 0, 7, 0, 7, 8, 15);
    addHealth(20);
}