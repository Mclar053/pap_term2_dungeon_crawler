//
//  Tile.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 03/03/2016.
//
//

#include "Tile.hpp"

Tile::Tile(ofVec2f _pos):GameObject(_pos){
    
}

void Tile::subDisplay(){
    gameSprite.display();
}