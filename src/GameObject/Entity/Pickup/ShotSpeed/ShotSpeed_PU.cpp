//
//  ShotSpeed_PU.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 19/03/2016.
//
//

#include "ShotSpeed_PU.hpp"
#include "../../../Entity/Player/Player.h"

Pickup_ShotSpeed::Pickup_ShotSpeed(ofVec2f _pos, float _val):Pickup(_pos,_val){
    gameSprite = Sprite("shotSpeed_pu");
}

void Pickup_ShotSpeed::collisionResponse(GameObject* other){
    Player* _player = dynamic_cast<Player*>(other);
    if(_player){
        _player->changeShotSpeed(this->getValue());
        this->die();
    }
}