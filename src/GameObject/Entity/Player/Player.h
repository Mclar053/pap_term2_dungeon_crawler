//
//  Player.h
//  dungeon_crawler
//
//  Created by Matthew Clark on 25/02/2016.
//
//

#ifndef __dungeon_crawler__Player__
#define __dungeon_crawler__Player__

#include <stdio.h>
#include "../Entity.h"

class Player: public Entity{
    
    
public:
    Player();
    Player(ofVec2f _pos);
};

#endif /* defined(__dungeon_crawler__Player__) */
