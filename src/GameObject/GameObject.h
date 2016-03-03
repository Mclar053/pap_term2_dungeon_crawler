//
//  GameObject.h
//  dungeon_crawler
//
//  Created by Matthew Clark on 16/02/2016.
//
//

#ifndef __dungeon_crawler__GameObject__
#define __dungeon_crawler__GameObject__

#include "../ofMain.h"
#include "../Sprite/Sprite.h"
#include <stdio.h>

//Abstract class
class GameObject{
    
protected:
    Sprite gameSprite;
    ofVec2f pos;
    ofVec2f size;
    
public:
    GameObject();
    GameObject(ofVec2f _pos);
    //Methods
    virtual void display(); //Virtual to allow other child classes to overwrite it. Pure virtual function.
    ofVec2f getSize(); //Gets size of the gameSprite
    ofVec2f getPos(); //Get position of player
    void setPos(ofVec2f _pos);
    
    virtual ~GameObject(){};
    
    
};


#endif /* defined(__dungeon_crawler__GameObject__) */
