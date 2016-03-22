//
//  Floor.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 06/02/2016.
//
//

#include "Floor.h"

Floor::Floor(int _floorNum):floorNum(_floorNum),currentRoom(0){
    //Create new floormaker to make a new floor for the current floor level
    fm = new Floormaker(20,20,floorNum);
    fm->generateFloor(); //Generate the floor
    grid = fm->getGrid(); //Get the grid of the floor
    generateFloor(); //Generate objects on the floor (Rooms, enemies, etc.)
    spawnRoom = findSpawn(); //Find the spawn room
    currentRoom = spawnRoom; //Set the current room to the spawn room
    currentGridPos = findSpawnGridPos(); //Get the current grid position of the spawn room
    
    //Remove floormaker as soon as it is not needed
    delete fm;
    fm = nullptr;
}

//Generates rooms based off of the grid received from the floormaker
void Floor::generateFloor(){
    //Loops through the grid
    for(int i=0; i<grid[0].size(); i++){
        for(int j=0; j<grid.size(); j++){
            //Gets the room adjacencies for the room
            vector<bool> roomAdjacent = checkAdjacencies(i, j);
            
            //Checks the type of room
            switch(grid[j][i]){
                case 3: case 4: //Normal room and normal end room
                    rooms.push_back(new NormalRoom(true,GridPos(j,i),roomAdjacent[0],roomAdjacent[1],roomAdjacent[2],roomAdjacent[3]));
                    break;
                    
                case 5://Item room
                    rooms.push_back(new ItemRoom(true,GridPos(j,i),roomAdjacent[0],roomAdjacent[1],roomAdjacent[2],roomAdjacent[3]));
                    break;
                    
                case 6: //Shop room
                    rooms.push_back(new ShopRoom(true,GridPos(j,i),roomAdjacent[0],roomAdjacent[1],roomAdjacent[2],roomAdjacent[3]));
                    break;
                    
                case 7: //Boss room
                    rooms.push_back(new BossRoom(true,GridPos(j,i),roomAdjacent[0],roomAdjacent[1],roomAdjacent[2],roomAdjacent[3]));
                    break;
                    
                case 9: //Spawn room
                    rooms.push_back(new SpawnRoom(false,GridPos(j,i),roomAdjacent[0],roomAdjacent[1],roomAdjacent[2],roomAdjacent[3]));
                    break;
            }
        }
    }
}

//Returns the position of the spawn room in the rooms vector
int Floor::findSpawn(){
    //Loops through all the rooms in the rooms vector
    for(int i=0; i<rooms.size(); i++){
        if(SpawnRoom* derived = dynamic_cast<SpawnRoom*> (rooms[i])){ //Checks for the spawn room
            return i; //Returns the spawn room position
        }
    }
    return 0; //Returns the 1st position in the vector
}

//Finds the grid position of the spawn room
GridPos Floor::findSpawnGridPos(){
    //Loops through the grid
    for(int i=0; i<grid[0].size(); i++)
        for(int j=0; j<grid.size(); j++){
            //Checks for spawn room (9)
            if(grid[j][i]==9)
                return GridPos(j,i); //Returns the spawn room grid pos
        }
    return GridPos(0,0); //Return a grid pos of (0,0)
}

//Checks for the room adjacencies
vector<bool> Floor::checkAdjacencies(int _i, int _j){
    vector<bool> _adjacent; //Set up a vector of bools
    
    //Check if the grid position above is within the vector bounds
    if(_j-1>=0){
        //Checks if the grid position above is not = 0 (is a room, not just blank space)
        if(grid[_j-1][_i]!=0) _adjacent.push_back(true);//If so, say that there is a room there
        else {_adjacent.push_back(false);}//If not, say there is not a room there
    }
    else {_adjacent.push_back(false);}

    //Check if the grid position to the right is within the vector bounds
    if(_i+1<grid[0].size()){
        //Checks if the grid position to the right is not = 0 (is a room, not just blank space)
        if(grid[_j][_i+1]!=0) _adjacent.push_back(true); //If so, say that there is a room there
        else{ _adjacent.push_back(false);} //If not, say there is not a room there
    }
    else {_adjacent.push_back(false);}
    
    //Check if the grid position below is within the vector bounds
    if(_j+1<grid.size()){
        //Checks if the grid position below is not = 0 (is a room, not just blank space)
        if(grid[_j+1][_i]!=0) _adjacent.push_back(true);//If so, say that there is a room there
        else{ _adjacent.push_back(false);}//If not, say there is not a room there
    }
    else {_adjacent.push_back(false);}
    
    //Check if the grid position to the left is within the vector bounds
    if(_i-1>=0){
        //Checks if the grid position to the left is not = 0 (is a room, not just blank space)
        if(grid[_j][_i-1]!=0) _adjacent.push_back(true);//If so, say that there is a room there
        else{ _adjacent.push_back(false);}//If not, say there is not a room there
    }
    else{ _adjacent.push_back(false);}
    
    return _adjacent; //Return the adjacency vector
}

//Returns the current room the player is on
Room* Floor::getRoom(){
    return rooms[currentRoom];
}

//Moves to another room
void Floor::moveRoom(GridPos _pos){
    //Adds a grid position to the current grid position
    currentGridPos.add(_pos);
    int oldRoom = currentRoom; //Keep a temp variable of the current room

    //Loop through all rooms
    for(int i=0; i<rooms.size(); i++){
        //Check if the rooms floor position is equal to the current grid position the player is now at
        if(rooms[i]->getFloorPos().isEqual(currentGridPos)){
            currentRoom=i; //If so, change the current room
        }
    }
    if(oldRoom==currentRoom){ //If the room hasn't changed
        currentGridPos.sub(_pos); //Remove the change that has been passed in
    }
}

//Return the floor grid
vector<vector<int>> Floor::getGrid(){
    return grid;
}