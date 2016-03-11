//
//  Door.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 29/02/2016.
//
//

#include "Door.hpp"

Door::Door(ofVec2f _pos, int _direction):GameObject(_pos), open(true){
    gameSprite = Sprite("door");
    calcRotation(_direction);
}

void Door::subDisplay(){
    ofRotate(rotation);
    gameSprite.display();
}

void Door::calcRotation(int _dir){
    rotation = ofMap(_dir,0,4,0,360);
}

bool Door::checkOpen(){
    return open;
}

/*
 Detects if Player has hit the left side of the door
 */
bool Door::detectLeft(Player &_player){
    if(_player.getPos().x+_player.getSize().x/2>getPos().x-getSize().x/2 &&
       _player.getPos().x-_player.getSize().x/2<getPos().x-getSize().x/2+5 &&
       _player.getPos().y+_player.getSize().y/2>getPos().y-getSize().y/2+10 &&
       _player.getPos().y-_player.getSize().y/2<=getPos().y+getSize().y/2-10){
        return true;
    }
    return false;
}

/*
 Detects if Player has hit the right side of the door
 */
bool Door::detectRight(Player &_player){
    if(_player.getPos().x+_player.getSize().x/2>getPos().x+getSize().x/2-5 &&
       _player.getPos().x-_player.getSize().x/2<getPos().x+getSize().x/2 &&
       _player.getPos().y+_player.getSize().y/2>getPos().y-getSize().y/2+10 &&
       _player.getPos().y-_player.getSize().y/2<=getPos().y+getSize().y/2-10){
        return true;
    }
    return false;
}

/*
 Detects if Player has hit the top side of the door
 */

bool Door::detectTop(Player &_player){
    if(_player.getPos().x+_player.getSize().x/2>getPos().x-getSize().x/2+10 &&
       _player.getPos().x-_player.getSize().x/2<=getPos().x+getSize().x/2-10 &&
       _player.getPos().y+_player.getSize().y/2>getPos().y-getSize().y/2 &&
       _player.getPos().y-_player.getSize().y/2<getPos().y-getSize().y/2+2){
        return true;
    }
    return false;
}

/*
 Detects if Player has hit the bottom side of the door
 */
bool Door::detectBottom(Player &_player){
    if(_player.getPos().x+_player.getSize().x/2>getPos().x-getSize().x/2+10 &&
       _player.getPos().x-_player.getSize().x/2<=getPos().x+getSize().x/2-10 &&
       _player.getPos().y+_player.getSize().y/2>getPos().y+getSize().y/2-2 &&
       _player.getPos().y-_player.getSize().y/2<getPos().y+getSize().y/2){
        return true;
    }
    return false;
}
