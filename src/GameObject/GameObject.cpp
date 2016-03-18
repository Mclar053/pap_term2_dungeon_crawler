//
//  GameObject.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 16/02/2016.
//
//

#include "GameObject.h"

GameObject::GameObject(){}

GameObject::GameObject(ofVec2f _pos):pos(_pos),dead(false){

}

//Displays the gamesprite and places the sprite into the correct position on the screen
void GameObject::display(){
    glPushMatrix();
    glTranslated(pos.x, pos.y, 0);
    subDisplay();
    glPopMatrix();
}

/*
 Detects if 'other GO' has hit the left side of the 'current GO'
 */
bool GameObject::collideLeft(GameObject* other){
    if(other->getPos().x+other->getSize().x/2>this->getPos().x-this->getSize().x/2 &&
       other->getPos().x-other->getSize().x/2<this->getPos().x-this->getSize().x/2+5 &&
       other->getPos().y+other->getSize().y/2>this->getPos().y-this->getSize().y/2+10 &&
       other->getPos().y-other->getSize().y/2<=this->getPos().y+this->getSize().y/2-10){
        return true;
    }
    return false;
}

/*
 Detects if 'other GO' has hit the right side of the 'current GO'
 */
bool GameObject::collideRight(GameObject* other){
    if(other->getPos().x+other->getSize().x/2>this->getPos().x+this->getSize().x/2-5 &&
       other->getPos().x-other->getSize().x/2<this->getPos().x+this->getSize().x/2 &&
       other->getPos().y+other->getSize().y/2>this->getPos().y-this->getSize().y/2+10 &&
       other->getPos().y-other->getSize().y/2<=this->getPos().y+this->getSize().y/2-10){
        return true;
    }
    return false;
}

/*
 Detects if 'other GO' has hit the top side of the 'current GO'
 */

bool GameObject::collideTop(GameObject* other){
    if(other->getPos().x+other->getSize().x/2>this->getPos().x-this->getSize().x/2+10 &&
       other->getPos().x-other->getSize().x/2<=this->getPos().x+this->getSize().x/2-10 &&
       other->getPos().y+other->getSize().y/2>this->getPos().y-this->getSize().y/2 &&
       other->getPos().y-other->getSize().y/2<this->getPos().y-this->getSize().y/2+2){
        return true;
    }
    return false;
}

/*
 Detects if 'other GO' has hit the bottom side of the 'current GO'
 */
bool GameObject::collideBottom(GameObject* other){
    if(other->getPos().x+other->getSize().x/2>this->getPos().x-this->getSize().x/2+10 &&
       other->getPos().x-other->getSize().x/2<=this->getPos().x+this->getSize().x/2-10 &&
       other->getPos().y+other->getSize().y/2>this->getPos().y+this->getSize().y/2-2 &&
       other->getPos().y-other->getSize().y/2<this->getPos().y+this->getSize().y/2){
        return true;
    }
    return false;
}

bool GameObject::collide(GameObject* other){
    if(this->collideLeft(other) || this->collideRight(other) || this->collideTop(other) || this->collideBottom(other)){
        return true;
    }
    return false;
}

// Does nothing by default
void GameObject::collisionResponse(GameObject *other)
{
    
}

void GameObject::die(){
    dead = true;
}
