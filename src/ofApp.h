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
		
        void loadImages(); //Loads all images into the image manager
        void checkDead(); //Checks if projectiles are 'dead' if so then delete object and remove pointer
        void killBullets(); //Kills all the bullets on screen
    
        void reset(); //Resets the whole game
    
        Floor* floor; //The current floor
        Room* currentRoom; //The current room the screen is displaying
        vector<vector<int>> grid; //Grid used for the mini map in the top left corner of the game screen
        int lvl; //The current floor level
        int size; //The size of the grid squares for the mini map
        Player* player; //The player
        bool nextFloor; //Checks if the player has collided with the end floor trapdoor to move to the next floor
    
        int gameState; //Checks what part of the game the player is at (Main menu, main game and game over)
    
        bool shootLeft, shootRight, shootUp, shootDown; //Checks where the player is firing
    
        vector<Projectile*> bullets; //Vector of projectiles that the player fires
    
    ofTrueTypeFont* font; //Font to display text onto the screen
    ofSoundPlayer music; //Sound Player for the music to play through
    

    
};
