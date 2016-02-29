//
//  Sprite.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#ifndef __UltraCrateBox__Sprite__
#define __UltraCrateBox__Sprite__

#include <stdio.h>
#include "../ofMain.h"

class Sprite{
    vector<ofImage> images;
    int upStart, upEnd; //Frames for up movement
    int downStart, downEnd; //Frames for down movement
    int rightStart, rightEnd; //Frames for left and right movement
    
    int currentFrame;
public:
    //Constructors
    Sprite();
    Sprite(string _baseFile);
    Sprite(string _baseFile, int _totalImage, int _upStart, int _upEnd, int _downStart, int _downEnd, int _rightStart, int _rightEnd);
    
    //Methods
    void createSprite(string _folderPath);
    void createSpriteIM(string _fileBase, int _totalImage); //Creates sprite with Image Manager
    void display();
    void moveNextFrame(int _start, int _end); //Moves sprite to the next frame
    
    //Getters
    vector<int> getUp();
    vector<int> getDown();
    vector<int> getHorizontal();
    int getSpriteSize();
    int getCurrentFrame();
    ofVec2f getSize();
    //Setters
    void setCurrentFrame(int _frame);
    
    
};

#endif /* defined(__UltraCrateBox__Sprite__) */