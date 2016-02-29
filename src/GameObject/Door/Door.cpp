//
//  Door.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 29/02/2016.
//
//

#include "Door.hpp"

Door::Door(ofVec2f _pos, int _direction):GameObject(_pos){
    gameSprite = Sprite("door");
}

void Door::display(){
    ofPushMatrix();
        ofTranslate(pos.x, pos.y);
        ofRotate(rotation, 0, 0, 0);
        gameSprite.display();
    ofPopMatrix();
}

void Door::calcRotation(int _dir){
    rotation = ofMap(_dir,0,4,0,360);
}