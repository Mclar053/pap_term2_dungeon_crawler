//
//  BossFloor.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 19/03/2016.
//
//

#include "BossFloor.hpp"

BossFloor::BossFloor(ofVec2f _pos):Tile(_pos){
    gameSprite = Sprite("bossfloor");
}