//
//  FireRate_PU.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 19/03/2016.
//
//

#include "FireRate_PU.hpp"
#include "../../../Entity/Player/Player.h"

Pickup_FireRate::Pickup_FireRate(ofVec2f _pos, float _val):Pickup(_pos,_val){
    gameSprite = Sprite("firerate_pu");
}

void Pickup_FireRate::collisionResponse(GameObject* other){
    Player* _player = dynamic_cast<Player*>(other);
    if(_player){
        _player->changeFireRate(this->getValue());
        this->die();
    }
}