#ifndef WARP_H
#define WARP_H

#include <cstdlib>
#include "FileProcessor.h"
using namespace std;

//forward declaration of Objects
class Objects;

//Warp class
class Warp{

    public:
        Warp(); //default constructor 
        ~Warp(); //default destructor

        //core functions
        void warpRandom(unsigned int seed, FileProcessor* myFP); //function to get a random coordinate for Warp

        int warpLocationX; //coordinate on X axis for Warp
        int warpLocationY; //coordinate on Y axis for Warp

    private:


};

#endif