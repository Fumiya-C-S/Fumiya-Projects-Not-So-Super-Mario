#include "Koopa.h"

//default constructor
Koopa::Koopa(){}
//default destructor
Koopa::~Koopa(){}

//interact function
//calculates whether mario wins or loses in a battle against Koopa
bool Koopa::interact(unsigned int seed){
    srand(seed);
    int random = rand() % 100; //get a random number between 0-99

    if (random < 65){ // if number is 0-64 (65% chance) Mario wins
        return true;
    } else { //if number is 69-99 (355 chance) Mario loses
        return false;
    }
}
