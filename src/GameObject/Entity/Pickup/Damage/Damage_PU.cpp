//
//  Damage_PU.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 19/03/2016.
//
//

#include "Damage_PU.hpp"
#include "../../../Entity/Player/Player.h"

Pickup_Damage::Pickup_Damage(ofVec2f _pos, float _val):Pickup(_pos,_val){
    gameSprite = Sprite("damage_pu");
}

void Pickup_Damage::collisionResponse(GameObject* other){
    Player* _player = dynamic_cast<Player*>(other);
    if(_player){
        _player->changeDamage(this->getValue());
        this->die();
    }
}