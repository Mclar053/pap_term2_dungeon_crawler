//
//  Door.hpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 29/02/2016.
//
//

#ifndef Door_hpp
#define Door_hpp

#include <stdio.h>
#include "../GameObject.h"
#include "../Entity/Player/Player.h"

class Door: public GameObject{
    float rotation;
    bool open;
    
public:
    Door(ofVec2f _pos, int _direction);
    void calcRotation(int _dir);
    void display();
    bool checkOpen();
    
    bool detectLeft(Player &_player);
    bool detectRight(Player &_player);
    bool detectTop(Player &_player);
    bool detectBottom(Player &_player);
    
};

#endif /* Door_hpp */
