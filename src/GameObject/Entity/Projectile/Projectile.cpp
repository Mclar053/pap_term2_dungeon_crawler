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

void Projectile::collisionResponse(GameObject* other){
    Enemy* _ene = dynamic_cast<Enemy*>(other);
    if(_ene){
        _ene->takeDamage(damage);
        this->die();
    }
}