//
//  NormalRoom.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 11/02/2016.
//
//

#include "NormalRoom.h"

NormalRoom::NormalRoom(){

}

NormalRoom::NormalRoom(bool _fight, GridPos _fPos, bool _left,bool _up, bool _right, bool _down):Room(false,_fPos,_left,_up,_right,_down){
    generateRoom();//Generates room
    checkOpenDoors(); //Checks if doors can be opened after generating the room
}

void NormalRoom::subGenerateRoom(){
    //Adds the normal floor tiles to cover the floor of the room
    for(int i=0; i<grid[0].size(); i++){
        for(int j=0; j<grid.size(); j++){
            tiles.push_back(new FloorTile(ofVec2f(62.5+i*25, 162.5+j*25)));
        }
    }
    //Generates the enemies
    generateEnemies();
}

void NormalRoom::generateEnemies(){
    //Generates a random number from 0-6
    int randomNum = floor(ofRandom(0,6));
    
    switch (randomNum) {
        case 0: //Generates 1 Guy Enemy
            enemies.push_back(new Enemy_Guy(ofVec2f(400,375)));
            break;
        case 1:// Generates 2 Pop Enemies
            enemies.push_back(new Enemy_Pop(ofVec2f(200,375)));
            enemies.push_back(new Enemy_Pop(ofVec2f(600,375)));
            break;
        case 2: //Generates 4 Guy Enemies
            enemies.push_back(new Enemy_Guy(ofVec2f(200,375)));
            enemies.push_back(new Enemy_Guy(ofVec2f(600,375)));
            enemies.push_back(new Enemy_Guy(ofVec2f(400,275)));
            enemies.push_back(new Enemy_Guy(ofVec2f(400,475)));
            break;
        case 3: //Generates 2 Pop and 2 Guy Enemies
            enemies.push_back(new Enemy_Pop(ofVec2f(200,375)));
            enemies.push_back(new Enemy_Pop(ofVec2f(600,375)));
            enemies.push_back(new Enemy_Guy(ofVec2f(400,400)));
            enemies.push_back(new Enemy_Guy(ofVec2f(400,350)));
            break;
        case 4: //Generates 2 Pop and 2 Whizz Enemies
            enemies.push_back(new Enemy_Pop(ofVec2f(200,375)));
            enemies.push_back(new Enemy_Pop(ofVec2f(600,375)));
            enemies.push_back(new Enemy_Whizz(ofVec2f(200,350)));
            enemies.push_back(new Enemy_Whizz(ofVec2f(600,400)));
            break;
        case 5: //Generates 3 Guy, 2 Pop and 2 Whizz Enemies
            enemies.push_back(new Enemy_Guy(ofVec2f(400,400)));
            enemies.push_back(new Enemy_Guy(ofVec2f(400,350)));
            enemies.push_back(new Enemy_Guy(ofVec2f(400,500)));
            enemies.push_back(new Enemy_Pop(ofVec2f(200,375)));
            enemies.push_back(new Enemy_Pop(ofVec2f(600,375)));
            enemies.push_back(new Enemy_Whizz(ofVec2f(200,350)));
            enemies.push_back(new Enemy_Whizz(ofVec2f(600,400)));
            break;
        default:
            break;
    }
}