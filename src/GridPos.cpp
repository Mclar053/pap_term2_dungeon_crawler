//
//  GridPos.cpp
//  Floor-Generator
//
//  Created by Matthew Clark on 25/01/2016.
//  Copyright (c) 2016 Matthew Clark. All rights reserved.
//

#include "GridPos.h"

GridPos::GridPos(int _x, int _y):x(_x),y(_y){}

void GridPos::add(GridPos _x){
    x+=_x.x;
    y+=_x.y;
}

void GridPos::set(int _x, int _y){
    x=_x;
    y=_y;
}