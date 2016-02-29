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
    
public:
    GameObject();
    GameObject(ofVec2f _pos);
    //Methods
    virtual void display() =0; //Virtual to allow other child classes to overwrite it. Pure virtual function.
    void getSize(); //Gets size of the gameSprite
    
    //Properties
    Sprite gameSprite;
    ofVec2f pos;
    ofVec2f size;
    
};


#endif /* defined(__dungeon_crawler__GameObject__) */
