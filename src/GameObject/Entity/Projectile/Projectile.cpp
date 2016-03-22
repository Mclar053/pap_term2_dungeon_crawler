//
//  Projectile.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 18/03/2016.
//
//

#include "Projectile.hpp"
#include "../Enemy/Enemy.hpp"

Projectile::Projectile(ofVec2f _pos, float _maxVel, float _damage):Entity(_pos,_maxVel),damage(_damage){
    gameSprite = Sprite("bullet");
}

//Collision Response damages enemies
void Projectile::collisionResponse(GameObject* other){
    //Tries to cast for an enemy type object
    Enemy* _ene = dynamic_cast<Enemy*>(other);
    if(_ene){//Checks if the casted object is an enemy
        _ene->takeDamage(damage);//Take damage from enemy
        this->die();//Kill the current object
    }
}