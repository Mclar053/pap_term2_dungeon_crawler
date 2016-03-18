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
    float fireRate;
    float damage;
    float shotSpeed;
    
    int lastFireFrame;
    bool checkFire(); //Checks if player can fire bullet
    
public:
    Player();
    Player(ofVec2f _pos);

    bool fire(); //Allows player to fire bullet at their firerate
    
    //Returns firerate
    float getFireRate(){
        return fireRate;
    }
    
    //Returns players damage
    float getDamage(){
        return damage;
    }
    
    //Return shotspeed of the bullets
    float getShotSpeed(){
        return shotSpeed;
    }
};

#endif /* defined(__dungeon_crawler__Player__) */
