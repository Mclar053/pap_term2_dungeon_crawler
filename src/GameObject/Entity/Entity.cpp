//
//  Entity.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 16/02/2016.
//
//

#include "Entity.h"

Entity::Entity(ofVec2f _pos, float _maxVel,int _iFrames):GameObject(_pos),left(false),right(false),up(false),down(false),moving(false),MAX_VEL(_maxVel),direction(1),iFrames(_iFrames),lastFrames(0),health(0){
    
}

void Entity::subDisplay(){
    glScalef(direction, 1, 1);
    
    gameSprite.display();
    if(moving){
        gameSprite.moveNextFrame(spriteStart,spriteEnd);
    }
    else{
        gameSprite.setCurrentFrame(spriteStart);
    }
}

void Entity::move(){
    acc.set(0,0);
    if(right){
        acc.x = 1;
        direction = 1;
        spriteStart = gameSprite.getHorizontal()[0];
        spriteEnd = gameSprite.getHorizontal()[1];
    } else if(left){
        acc.x = -1;
        direction = -1;
        spriteStart = gameSprite.getHorizontal()[0];
        spriteEnd = gameSprite.getHorizontal()[1];
    }
    
    if(down){
        direction=1;
        spriteStart = gameSprite.getDown()[0];
        spriteEnd = gameSprite.getDown()[1];
        acc.y = 1;
    }else if(up){
        direction=1;
        spriteStart = gameSprite.getUp()[0];
        spriteEnd = gameSprite.getUp()[1];
        acc.y = -1;
    }
    
    moving = checkMoving(); // Checks if the entity is moving
    
    acc.normalize(); //Ensures magnitude of acc is 1
    acc/=2; //Halves the acc (doesn't speed up as fast)
    
    vel += acc; //Add acc to velocity
    vel.x=friction(vel.x); //Friction in the x direction
    vel.y=friction(vel.y); //Friction in the y direction
    normaliseMaxSpeed(); //Speed control so entity doesn't move over Max velocity (MAX_VEL)
    
    if(!edgeDetect()){ //Checks if player has hit room edge
        pos += vel; //Add velocity to position
    }
}

float Entity::friction(float _vel){
    if(_vel>0.2) _vel-=0.1;
    else if(_vel<-0.2) _vel+=0.1;
    else _vel = 0;
    return _vel;
}

float Entity::speedControl(float _ratio){
    return MAX_VEL*_ratio;
}

void Entity::normaliseMaxSpeed(){
    if(vel.length()>MAX_VEL){
        ofVec2f ratio = vel;
        ratio.normalize();
        vel.x = speedControl(ratio.x);
        vel.y = speedControl(ratio.y);
    }
}

bool Entity::edgeDetect(){
    if(pos.x+vel.x-getSize().x/2<48 || pos.x+vel.x+getSize().x/2>752 || pos.y+vel.y-getSize().y/2<148 || pos.y+vel.y+getSize().y/2>602){
        return true;
    }
    return false;
}

void Entity::moveLeft(){
    left = true;
}

void Entity::moveRight(){
    right=true;
}

void Entity::moveUp(){
    up = true;
}

void Entity::moveDown(){
    down = true;
}

void Entity::stopLeft(){
    left = false;
}

void Entity::stopRight(){
    right=false;
}

void Entity::stopUp(){
    up = false;
}

void Entity::stopDown(){
    down = false;
}

bool Entity::checkMoving(){
    if(left || right || up || down){
        return true;
    }
    return false;
}

void Entity::reset(){
    acc.set(0,0);
    left=false;
    right=false;
    up=false;
    down=false;
}

// reduce health and die of health reaches 0
void Entity::takeDamage(float d)
{
    if(checkDamage()){ //Checks if the entity can take damage
        health -= d;
        lastFrames = ofGetFrameNum();
        if (health <= 0){
            die();
        }
    }
}

// increase health
void Entity::addHealth(float h)
{
    health += h;
}

//Checks if the entity is still invincible from the last time the entity has been hit
bool Entity::checkDamage(){
    if(lastFrames+iFrames>ofGetFrameNum()){
        return false;
    }
    return true;
}