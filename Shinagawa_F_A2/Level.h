#ifndef LEVEL_H
#define LEVEL_H

#include "FileProcessor.h"
#include <random>
#include <ctime>

//Level Class
class Level{
    public:
        Level(FileProcessor* myFP); //default constructor
        ~Level(); //default destructor

        //core functions
        char** createLevel(FileProcessor* myFP, unsigned int seed); //function that creates a level and its objects and where they are placed

    private:
        char** world; //2D array to hold rows and columns of objects in level
        int cols; //int of length of dimension columns 
        int rows; //int of length for dimension rows

};

#endif