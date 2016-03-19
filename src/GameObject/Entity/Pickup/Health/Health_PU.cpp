//
//  Health_PU.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 19/03/2016.
//
//

#include "Health_PU.hpp"
#include "../../../Entity/Player/Player.h"

Pickup_Health::Pickup_Health(ofVec2f _pos, float _val):Pickup(_pos,_val){
    gameSprite = Sprite("health_pu");
}

void Pickup_Health::collisionResponse(GameObject* other){
    Player* _player = dynamic_cast<Player*>(other);
    if(_player){
        _player->addHealth(this->getValue());
        this->die();
    }
}