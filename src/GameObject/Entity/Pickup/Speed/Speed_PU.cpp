//
//  Speed_PU.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 19/03/2016.
//
//

#include "Speed_PU.hpp"
#include "../../../Entity/Player/Player.h"

Pickup_Speed::Pickup_Speed(ofVec2f _pos, float _val):Pickup(_pos,_val){
    gameSprite = Sprite("speed_pu");
}

void Pickup_Speed::collisionResponse(GameObject* other){
    Player* _player = dynamic_cast<Player*>(other);
    if(_player){
        _player->changeSpeed(this->getValue());
        this->die();
    }
}