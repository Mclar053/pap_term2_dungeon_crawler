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
    float rotation; //Rotation of the door so it looks right on the screen
    bool open; //Checks if the door is open or not
    
public:
    Door(ofVec2f _pos, int _direction);
    void calcRotation(int _dir); //Calculates a rotation based on the direction of the door
    void subDisplay(); //Displays the door
    bool checkOpen(); //Returns if the door is open or not
    
};

#endif /* Door_hpp */
