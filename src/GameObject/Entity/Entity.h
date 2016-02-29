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
    ofVec2f vel; //Velocity
    ofVec2f acc; //Acceleration
    bool moving;
    bool left, right, up, down;
    int direction; //States the direction the sprite is facing (-1=left, 1=right)
    
    int spriteStart, spriteEnd;
    
public:
    Entity(ofVec2f _pos = ofVec2f(200,200), float _maxVel = 5);
    
    void reset();
    
    void display();
    
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
    
    //Collisions
    bool edgeDetect();
    
    /*Features*/
    void wallWrap(); //Allows entities to move to other side of screen
    bool checkWallX(); //Checks between x<0 and x>width
    bool checkWallY(); //Checks between y<0 and y>height
};

#endif /* defined(__dungeon_crawler__Entity__) */
