//
//  Floormaker.h
//  Floor-Generator
//
//  Created by Matthew Clark on 25/01/2016.
//  Copyright (c) 2016 Matthew Clark. All rights reserved.
//

#ifndef __Floor_Generator__Floormaker__
#define __Floor_Generator__Floormaker__

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>

#include "GridPos.h"

using namespace std;

class Floormaker{
    float floorNum;
    vector<GridPos> spawnRoute;
    vector<vector<int>> grid;
    vector<int> availableRooms; //Rooms that are available to create
    GridPos spawn, current; //Origin point of floormaker
    vector<GridPos> endRoomLocations;
    
    bool complete;
    
public:
    Floormaker(int _sX=7, int _sY=7, float _fNum=1);
    void generateSpawn();
    vector<vector<int>> resizeGrid(int _sX=7, int _sY=7);
    
    void generateFloor();
    
    //Room searching
    void searchRooms();
    vector<GridPos> searchRoomTypes(int _type);
    bool checkSide(int _vert=0, int _hori=0);
    GridPos chooseDirection(int _val);
    
    //Room creation
    void createRooms();
    
    bool checkRoomComplete();
    
    //Check out of bounds
    bool checkOutOfBoundsX(int _pos, int _vert, int _hori);
    bool checkOutOfBoundsY(int _pos, int _vert, int _hori);
    
    //Moving into/out of rooms
    void moveIntoRoom(GridPos _pos);
    void moveOutOfRoom();
    
    //Returns the grid
    vector<vector<int>> getUnformattedGrid();
    vector<vector<int>> getGrid();
    
    //Prints out grid
    void printGrid();
    
    //Checking rooms
    void createSpecialRooms(); //Checking end rooms
    bool enoughRooms();
};

#endif /* defined(__Floor_Generator__Floormaker__) */
