//
//  Entity.h
//  dungeon_crawler
//
//  Created by Matthew Clark on 16/02/2016.
//
//

#ifndef __dungeon_crawler__Entity__
#define __dungeon_crawler__Entity__

#include <stdio.h>
#include "../GameObject.h"

class Entity: public GameObject{
    float MAX_VEL; //Maximum Velocity
    float MAX_HEALTH; //Maximum Health
    ofVec2f vel; //Velocity
    ofVec2f acc; //Acceleration
    bool moving;
    bool left, right, up, down;
    int direction; //States the direction the sprite is facing (-1=left, 1=right)
    
    //Health value
    float health;
    
    //Current start and end of sprite animation
    int spriteStart, spriteEnd;
    
    int lastFrames; //Reference for invincibility
    int iFrames; //Invincibilty frames
    
public:
    Entity(ofVec2f _pos = ofVec2f(200,200), float _maxVel = 5, float _maxHealth = 1, int _iFrames = 0);
    
    //Stops all movement
    void reset();
    
    //Draws to screen the gameSprite
    void subDisplay();
    
    /*Physics*/
    void move();
    float friction(float _vel);
    float speedControl(float _ratio);
    void normaliseMaxSpeed();
    
    /*Movement*/
    //Moving in all directions
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    
    //Stopping in all directions
    void stopLeft();
    void stopRight();
    void stopUp();
    void stopDown();
    
    //Checks if entity is moving
    bool checkMoving();
    
    //Returns velocity of Entity
    ofVec2f getVel();
    
    //Wall Collisions
    bool edgeDetect();
    
    /*Features*/
    void wallWrap(); //Allows entities to move to other side of screen
    bool checkWallX(); //Checks between x<0 and x>width
    bool checkWallY(); //Checks between y<0 and y>height
    
    virtual void movePattern(){};
    virtual void moveNextPattern(){};
    
    void takeDamage(float d);
    
    void addHealth(float h);
    
    //Checks if entity can be damaged
    bool checkDamage();
    
    //Temporary
    float getHealth(){
        return health;
    }
    
    float getMaxHealth(){
        return MAX_HEALTH;
    }
};

#endif /* defined(__dungeon_crawler__Entity__) */
