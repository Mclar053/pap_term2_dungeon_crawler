//
//  FloorTile.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 03/03/2016.
//
//

#include "FloorTile.hpp"

FloorTile::FloorTile(ofVec2f _pos):Tile(_pos){
    gameSprite = Sprite("floor");
}