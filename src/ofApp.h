#pragma once

#include "ofMain.h"
#include "Floormaker.h"
#include "Floor/Floor.h"
#include "Room/Room.h"
#include "GameObject/Entity/Player/Player.h"
#include "GameObject/Entity/Enemy/Guy/Guy.hpp"
#include "GameObject/Entity/Projectile/Projectile.hpp"

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
		
        void loadImages();
        void checkDead(); //Checks if projectiles are 'dead' if so then delete object and remove pointer
        void killBullets();
    
        Floor* floor;
        Room* currentRoom;
        vector<vector<int>> grid, grid2;
        int lvl;
        int size;
        Player* player;
    
        bool shootLeft, shootRight, shootUp, shootDown;
    
        vector<Projectile*> bullets;
    
    ofTrueTypeFont* font;
    ofSoundPlayer music;
    

    
};
