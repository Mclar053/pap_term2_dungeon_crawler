//
//  NormalRoom.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 11/02/2016.
//
//

#include "NormalRoom.h"

NormalRoom::NormalRoom():Room(true){

}

NormalRoom::NormalRoom(bool _fight, GridPos _fPos, bool _left,bool _up, bool _right, bool _down):Room(false,_fPos,_left,_up,_right,_down){
    generateRoom();
}

void NormalRoom::subGenerateRoom(){
    enemies.push_back(new Enemy_Guy());
    enemies.push_back(new Enemy_Pop());
}