//
//  GridPos.cpp
//  Floor-Generator
//
//  Created by Matthew Clark on 25/01/2016.
//  Copyright (c) 2016 Matthew Clark. All rights reserved.
//

#include "GridPos.h"

GridPos::GridPos(int _x, int _y):x(_x),y(_y){}

//Adds another GridPos objects to current
void GridPos::add(GridPos _x){
    x+=_x.x;
    y+=_x.y;
}

//Subtracts another GridPos objects to current
void GridPos::sub(GridPos _x){
    x-=_x.x;
    y-=_x.y;
}

//Sets current GridPos
void GridPos::set(int _x, int _y){
    x=_x;
    y=_y;
}

//Checks if current GridPos is the same as another GridPos object
bool GridPos::isEqual(GridPos _gridpos){
    if(_gridpos.x==x && _gridpos.y==y)
        return true;
    return false;
}