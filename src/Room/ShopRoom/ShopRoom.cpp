//
//  ShopRoom.cpp
//  dungeon_crawler
//
//  Created by Matthew Clark on 11/02/2016.
//
//

#include "ShopRoom.h"

ShopRoom::ShopRoom():Room(false){
    
}

ShopRoom::ShopRoom(bool _fight, GridPos _fPos, bool _left,bool _up, bool _right, bool _down):Room(_fight,_fPos,_left,_up,_right,_down){
    generateRoom();
    checkOpenDoors();
}

//void ShopRoom::display(){
//    for(int i=0; i<grid[0].size(); i++){
//        for(int j=0; j<grid.size(); j++){
//            glPushMatrix();
//            glTranslated(50+i*25,150+j*25, 0);
//            ofPushStyle();
//            ofSetColor(255, 0, 255); //Magenta
//            ofDrawRectangle(0,0,25,25);
//            ofPopStyle();
//            glPopMatrix();
//        }
//    }
//    for(auto _door: doors){
//        _door->display();
//    }
//}

void ShopRoom::subGenerateRoom(){
    for(int i=0; i<grid[0].size(); i++){
        for(int j=0; j<grid.size(); j++){
            tiles.push_back(new FloorTile(ofVec2f(i*25, j*25)));
        }
    }
}