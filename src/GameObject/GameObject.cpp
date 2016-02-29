//
//  GameObject.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 16/02/2016.
//
//

#include "GameObject.h"

GameObject::GameObject(){
    
}

GameObject::GameObject(ofVec2f _pos){
    pos = _pos;
}

//Displays the gamesprite and places the sprite into the correct position on the screen
void GameObject::display(){
    glPushMatrix();
    glTranslated(pos.x, pos.y, 0);
    gameSprite.display();
    glPopMatrix();
}

//Gets size of gamesprite and sets the size to gamesprites current size
void GameObject::getSize(){
    size.set(gameSprite.getSize());
}