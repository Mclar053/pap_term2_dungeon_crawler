//
//  TrapDoor.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 19/03/2016.
//
//

#include "TrapDoor.hpp"

Trapdoor::Trapdoor(ofVec2f _pos):Tile(_pos){
    gameSprite = Sprite("trapdoor");
}