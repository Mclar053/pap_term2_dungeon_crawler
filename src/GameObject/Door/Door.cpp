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
    ofRotate(rotation); //Rotates the door by a set rotation
    gameSprite.display(); //Displays the game object
}

//Calculates a rotation based on the direction of the door
void Door::calcRotation(int _dir){
    rotation = ofMap(_dir,0,4,0,360);
}

bool Door::checkOpen(){
    return open;
}
