//
//  SpawnFloor.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 19/03/2016.
//
//

#include "SpawnFloor.hpp"

SpawnFloor::SpawnFloor(ofVec2f _pos):Tile(_pos){
    gameSprite = Sprite("spawnfloor");
}