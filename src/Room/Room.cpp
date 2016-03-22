//
//  Room.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 06/02/2016.
//
//

#include "Room.h"

Room::Room(bool _fight, GridPos _fPos ,bool _up,bool _right, bool _down, bool _left):sizeX(28),sizeY(18),floorPos(_fPos){
    
    grid.resize(sizeY);
    for(auto &_y: grid) _y.resize(sizeX);
    
    //Pushes where doors should spawn in the room
    roomAdjacency.push_back(_up);
    roomAdjacency.push_back(_right);
    roomAdjacency.push_back(_down);
    roomAdjacency.push_back(_left);
}

void Room::display(){
    
    //Display all tiles
    for(auto _tile: tiles){
        glPushMatrix();
        _tile->display();
        glPopMatrix();
    }
    
    //Display all doors
    for(auto _door: doors){
        _door->display();
    }
    
    //Displays all pickups
    for(auto _pu: pickups){
        _pu->display();
    }
    
    //Display all entities
    for(auto _ene: enemies){
        _ene->display();
    }
}


//Checks if pickups and enemies are dead and removes them if so
void Room::checkDead(){
    //Reference: Marco Gilles - ShooterInheritence
    //Link: 
    
    //Checks what enemies are 'Dead' and puts them to the end on the vector
    auto it = std::remove_if(enemies.begin(), enemies.end(),
                             [](Enemy *_ene){
                                 return !_ene->isAlive();
                             });
    //Cycles through all the enemies and checks if they are 'alive'
    //If not then delete the object in dynamic memory and set the pointer to null
    for(auto _ene: enemies){
        if(!_ene->isAlive()){
            addRandomPickup(_ene); //Add a random pickup where the enemy had died
            delete _ene;
            _ene = nullptr;
        }
    }
    //Remove all enemies that are 'dead'
    enemies.erase(it, enemies.end());
    
    //Check if all enemies have died and open doors in the current room if they are
    checkOpenDoors();
    
    //Checks what pickups are 'Dead' and puts them to the end on the vector
    auto it2 = std::remove_if(pickups.begin(), pickups.end(),
                             [](Pickup *_pu){
                                 return !_pu->isAlive();
                             });
    
    //Cycles through all the pickups and checks if they are 'alive'
    //If not then delete the object in dynamic memory and set the pointer to null
    for(auto _pu: pickups){
        if(!_pu->isAlive()){
            delete _pu;
            _pu = nullptr;
        }
    }
    
    //Remove all pickups that are 'dead'
    pickups.erase(it2, pickups.end());
    
}

//Checks what doors can be created from roomAdjacency vector
//Pushes back a new door in respective position
void Room::generateRoom(){
    //Creates rooms clockwise from up to left
    for(int i=0; i<roomAdjacency.size(); i++){
        ofVec2f _pos;
        if(roomAdjacency[i]){
            switch(i){
                case 1:
                    _pos = ofVec2f(775,375);
                    break;
                case 2:
                    _pos = ofVec2f(400,625);
                    break;
                case 3:
                    _pos = ofVec2f(25,375);
                    break;
                default:
                    _pos = ofVec2f(400,125);
                    break;
            }
            doors.push_back(new Door(_pos,i));
        }
    }
    
    subGenerateRoom();
}

//Adds random pickup from where the enemy has died
void Room::addRandomPickup(Enemy* _ene){
    //Chooses a random number from 1-6
    int randNum = ceil(ofRandom(0,6));
    
    switch(randNum){
        case 1://Health pickup (Heals 1-2)
            pickups.push_back(new Pickup_Health(_ene->getPos(),ceil(ofRandom(0,2))));
            break;
        case 2://Damage pickup (+/- 1)
            pickups.push_back(new Pickup_Damage(_ene->getPos(),ofRandom(-1,1)));
            break;
        case 3: //Shot speed pickup (+/- 1)
            pickups.push_back(new Pickup_ShotSpeed(_ene->getPos(),ofRandom(-1,1)));
            break;
        case 4: //Fire rate pickup (+/- 10)
            pickups.push_back(new Pickup_FireRate(_ene->getPos(),ofRandom(-10,10)));
            break;
        default: //Speed pickup (+/- 1)
            pickups.push_back(new Pickup_Speed(_ene->getPos(),ofRandom(-1,1)));
            break;
    }
}

//Checks if room is empty of enemies and sets the door sprite to the 'open' state
void Room::checkOpenDoors(){
    if(this->checkEmpty()){
        for(auto _door: doors){
            _door->changeSprite("opendoor");
        }
    }
}

//Checks if size of enemies vector is equal to 0
bool Room::checkEmpty(){
    if(enemies.size()==0){
        return true;
    }
    return false;
}

//Empty by default
void Room::generateEnemies(){
    
}

Room::~Room(){
    for(auto _d : doors){
        delete _d;
        _d = nullptr;
    }
    
    for(auto _t : tiles){
        delete _t;
        _t = nullptr;
    }
    
    for(auto _e: enemies){
        delete _e;
        _e = nullptr;
    }
    
    for(auto _pu: pickups){
        delete _pu;
        _pu = nullptr;
    }
}