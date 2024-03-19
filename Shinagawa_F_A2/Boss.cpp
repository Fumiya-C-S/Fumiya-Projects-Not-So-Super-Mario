#include "Boss.h"

//default constructor
Boss::Boss(){}

//default destructor
Boss::~Boss(){}

//interact function
//calculates whether mario wins or loses in a battle against Boss
bool Boss::interact(unsigned int seed){
    srand(seed);
    int random = rand() % 100; //get a random number 0-99 to determine Mario win/loss
    if (random < 50){ //if number is between 0-49 (50% chance) then Mario wins
        return true;
    } else { //if number is between 50-99 (50% chance) then Mario loses
        return false;
    }
}

//bossRandom function
//sets a random location on 
void Boss::bossRandom(unsigned int seed, FileProcessor* myFP){ 
    srand(seed);
    //gets a random number between 0 - worldSpecs[myFP->dimensions] which is the length of one side
    bossLocationX = rand() % myFP->worldSpecs[myFP->dimensions]; 
    bossLocationY = rand() % myFP->worldSpecs[myFP->dimensions];
}