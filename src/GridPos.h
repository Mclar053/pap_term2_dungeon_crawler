//
//  GridPos.h
//  Floor-Generator
//
//  Created by Matthew Clark on 25/01/2016.
//  Copyright (c) 2016 Matthew Clark. All rights reserved.
//

#ifndef __Floor_Generator__GridPos__
#define __Floor_Generator__GridPos__

#include <stdio.h>

class GridPos{
public:
    GridPos(int _x=0, int _y=0);
    int x,y;
    void add(GridPos _x);
    void sub(GridPos _x);
    void set(int _x, int _y);
    bool isEqual(GridPos _gridpos);
};

#endif /* defined(__Floor_Generator__GridPos__) */
