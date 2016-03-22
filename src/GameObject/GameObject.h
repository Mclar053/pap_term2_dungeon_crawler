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
    Sprite gameSprite; //Game sprite
    ofVec2f pos; //Position of the game object
    bool dead; //Says if game object is dead or not
    
public:
    GameObject();
    GameObject(ofVec2f _pos);
    //Methods
    
    // Main display function
    void display();
    
    //Allow subclasses to draw their own code. Can be overwritten.
    virtual void subDisplay()=0;
    
    //Gets size of the gameSprite
    ofVec2f getSize(){
        return gameSprite.getSize();
    }
    
    //Get position of gameObject
    ofVec2f getPos(){
        return pos;
    }
    
    //Sets the position of the game object
    void setPos(ofVec2f _pos){
        pos.set(_pos);
    }
    
    //Key Pressed. Empty by default
    virtual void keyPressed(int key){};
    
    //Sets dead bool to true
    virtual void die();
    
    //Changes the sprite of the game object
    void changeSprite(string _fileName);
    
    //Checks if object is alive
    bool isAlive(){
        return !dead;
    }
    
    //Individual collision checks
    bool collideTop(GameObject* other);
    bool collideLeft(GameObject* other);
    bool collideRight(GameObject* other);
    bool collideBottom(GameObject* other);
    bool collide(GameObject* other);
    
    //Calls response of collision with another gameobject
    virtual void collisionResponse(GameObject* other);
    
    virtual ~GameObject(){};
    
    
};


#endif /* defined(__dungeon_crawler__GameObject__) */
