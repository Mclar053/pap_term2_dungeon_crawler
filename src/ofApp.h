#pragma once

#include "ofMain.h"
#include "Floormaker.h"
#include "Floor/Floor.h"
#include "Room/Room.h"
//#include "GameObject/GameObject.h"
//#include "GameObject/Entity/Entity.h"
#include "GameObject/Entity/Player/Player.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
//        Floormaker fm;
        Floor floor;
        Room* currentRoom;
        vector<vector<int>> grid, grid2;
        int lvl;
        int size;
        Player ent = Player(ofVec2f(300,300));
    

    
};
