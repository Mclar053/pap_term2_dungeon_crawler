//
//  GameObject.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 16/02/2016.
//
//

#include "GameObject.h"

GameObject::GameObject(){}

GameObject::GameObject(ofVec2f _pos):pos(_pos){

}

//Displays the gamesprite and places the sprite into the correct position on the screen
void GameObject::display(){
    glPushMatrix();
    glTranslated(pos.x, pos.y, 0);
    gameSprite.display();
    glPopMatrix();
}

//Gets size of gamesprite and sets the size to gamesprites current size
ofVec2f GameObject::getSize(){
    return gameSprite.getSize();
}
ofVec2f GameObject::getPos(){
    return pos;
}

void GameObject::setPos(ofVec2f _pos){
    pos.set(_pos);
}