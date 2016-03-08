//
//  ImageManager.hpp
//  ImageManager
//
//  Created by Marco Gillies on 10/12/2015.
//
//

#ifndef ImageManager_hpp
#define ImageManager_hpp

#include <stdio.h>
#include <map>
#include <string>
#include "ofMain.h"


/* 
 *  This class is a central place to store all images used in 
 *  the game so you only have to load them into memory once.
 
 
 Reference: https://github.com/marcogillies/ImageManager
 Marco Gillies
 */
class ImageManager {
    // the images are stored in a map so you can
    // index them by name rather than a number
    std::map<string, ofImage *> images;
    
    // this is the singleton instance of the image
    // manager
    static unique_ptr<ImageManager> theImageManager;
    
    // the constructor is private so that it can only
    // be created via the static functions below
    ImageManager();
public:
    
    // get hold of the manager
    static ImageManager & get();
    
    ~ImageManager();
    
    // reset the manager (deletes all images)
    void reset();
    
    // loads an image from file and loads it
    void add(string filename);
    
    
    //--CHANGED to return pointer as const & cannot be contained in vector container--
    // gets an image by name
    ofImage* get(string name) const {
        return (images.at(name));
    };
    
};

#endif /* ImageManager_hpp */
