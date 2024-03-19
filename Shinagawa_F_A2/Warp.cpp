#include "Warp.h"
#include "Objects.h"

//default constructor
Warp::Warp(){}

//default destructor
Warp::~Warp(){}

//warpRandom function
//sets a random location on 
void Warp::warpRandom(unsigned int seed, FileProcessor* myFP){
    srand(seed);
    //gets a random number between 0 - worldSpecs[myFP->dimensions] which is the length of one side
    warpLocationX = rand() % myFP->worldSpecs[myFP->dimensions];
    warpLocationY = rand() % myFP->worldSpecs[myFP->dimensions];
}
