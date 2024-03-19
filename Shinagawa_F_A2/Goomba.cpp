#include "Goomba.h"

//default constructor
Goomba::Goomba(){}
//default destructor
Goomba::~Goomba(){}

//interact function
//calculates whether mario wins or loses in a battle against Goomba
bool Goomba::interact(unsigned int seed){
    srand(seed);
    int random = rand() % 100; //get random number between 0-99 to determine win or loss

    if (random < 80){ //if between 0-79 (80% chance) then Mario wins
        return true;
    } else { //if between 80-99 (20% chance) then Mario loses
        return false;
    }
}