//
//  ImageManager.cpp
//  ImageManager
//
//  Created by Marco Gillies on 10/12/2015.
//
//
//Reference: https://github.com/marcogillies/ImageManager

#include "ImageManager.hpp"

// the singleton instance, initially set to null
unique_ptr<ImageManager> ImageManager::theImageManager = nullptr;

// this it the singleton accessor
// gets hold of the single instance of the class
ImageManager & ImageManager::get(){
    // check whether the instance has been allocated
    // if not call reset (which allocates a new instance)
    if(!theImageManager){
        theImageManager.reset(new ImageManager());
    }
    // return the imagemanager
    return *(theImageManager.get());
}


// resets the image manager by deleting all of the images
// of course, I could have used unique_ptrs
// but i wanted to demonstrate how to manually
// delete stuff
void ImageManager::reset(){
    // iterate through all of the image
    // and deletel them.
    // Iterating through a map gives you a
    // set of pairs, the first element of which
    // is the key (string)
    // and the second is the value (image pointer)
    // we are deleting the second (which is the
    // actual image pointer)
    for(auto pair : images){
        delete pair.second;
    };
    // clear empties the map removing all elements
    images.clear();
};

// no need to do anything in the constructor
// because std::map is default constructed
ImageManager::ImageManager(){
    
};


// the destructor just calls reset which
// deletes all of the images
ImageManager::~ImageManager(){
    reset();
};

// loads a file and adds it to the map
void ImageManager::add(string filename){
    // allocate a new ofImage
    ofImage *img = new ofImage();
    // load from the file
    img->load(filename);
    // add it to the map
    // to add to a map you need to
    // add both a string name (which is the base file name)
    // and the image itself.
    // you can do it just by doing this:
    // images[ofFilePath::getBaseName(filename]  = img;
    // but I wanted to show you another way which explicitly
    // creates a pair, which is a datastructure for holding two
    // things together. 
    images.insert(make_pair(ofFilePath::getBaseName(filename), img));
    cout<<ofFilePath::getBaseName(filename)<<endl;
};