//
//  Sprite.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#include "Sprite.h"

Sprite::Sprite(){}

//Constructor for stationary sprites (Tiles, Weapons)
Sprite::Sprite(string _baseFile):currentFrame(0){
    createSpriteIM(_baseFile, 1);
    cout<<"hi"<<endl;
}

//Constructor for animated sprites (Entity)
Sprite::Sprite(string _baseFile, int _totalImage, int _upStart, int _upEnd,int _downStart, int _downEnd, int _rightStart, int _rightEnd):upStart(_upStart),upEnd(_upEnd),downStart(_downStart),downEnd(_downEnd),rightStart(_rightStart),rightEnd(_rightEnd){
        cout<<"hey"<<endl;
    currentFrame  = 0;
    createSpriteIM(_baseFile, _totalImage);
}

//Adds ofImage references to sprite vector
//_fileBase = base of file name
//_totalImage = total number of images for that file base name
void Sprite::createSpriteIM(string _fileBase, int _totalImage){
    for(int i=0; i<_totalImage; i++){
        cout<<_fileBase+to_string(i)<<endl;
        images.push_back(ImageManager::get().get(_fileBase+to_string(i)));
    }
}

//Display current frame of animation
void Sprite::display(){
    images[currentFrame]->draw(-images[currentFrame]->getWidth()/2, -images[currentFrame]->getHeight()/2, images[currentFrame]->getWidth(), images[currentFrame]->getHeight());
}

//Moves to next frame every 6 frames and loops the animation
void Sprite::moveNextFrame(int _start, int _end){
    if(ofGetFrameNum()%5==0){
        currentFrame++;
        if(currentFrame<_start || currentFrame>=_end){
            setCurrentFrame(_start);
        }
    }
}

//Returns start of the up movement of sprite
vector<int> Sprite::getUp(){
    vector<int> _up = {upStart, upEnd};
    return _up;
}

//Returns start of the down movement of sprite
vector<int> Sprite::getDown(){
    vector<int> _down = {downStart, downEnd};
    return _down;
}

//Returns start of the left/right movement of sprite
vector<int> Sprite::getHorizontal(){
    vector<int> _right = {rightStart, rightEnd};
    return _right;
}

int Sprite::getSpriteSize(){
    return images.size();
}

//Returns current frame of sprite
int Sprite::getCurrentFrame(){
    return currentFrame;
}

ofVec2f Sprite::getSize(){
    return ofVec2f(images[currentFrame]->getWidth(), images[currentFrame]->getHeight());
}

//Changes curent frame to one specified
void Sprite::setCurrentFrame(int _frame){
    currentFrame=_frame;
}
