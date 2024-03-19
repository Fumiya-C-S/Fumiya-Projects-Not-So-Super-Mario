#include "Mario.h"

//default constructor
Mario::Mario(FileProcessor* myFP){ 

    //initialize Mario's core member variables. Mario starts with 0 Coins, 0 Power Level, 0 Enemies Defeated, and Lifes initializes in WorldSpecs
    coins = 0;
    powerLevel = 0;
    enemiesDefeated = 0;
    lifes =  myFP->worldSpecs[myFP->initialLives]; 

    //get random seed for rand()
    srand((unsigned) time(NULL));
    //initialize random location for Mario
    locationX = rand() % myFP->worldSpecs[myFP->dimensions];
    locationY = rand() % myFP->worldSpecs[myFP->dimensions];
}

//default destructor
Mario::~Mario(){}

//marioRandom function
//gets a random starting point for Mario
void Mario::marioRandom(unsigned int seed, FileProcessor* myFP){
    srand(seed); //gets random seed for rand()
    //gets a random number between 0 - worldSpecs[myFP->dimensions] which is the length of one side
    locationX = rand() % myFP->worldSpecs[myFP->dimensions]; 
    locationY = rand() % myFP->worldSpecs[myFP->dimensions];
}

//printLocation function
//prints the current location of Mario
string Mario::printLocation(){
    returnString = "Mario is at Location: (" + to_string(locationX) + ", " + to_string(locationY) + ")\n";
    return returnString;
} 

//getCoin function
//function for when mario gets a coin, and when he reaches 20 coins
string Mario::getCoin(){
    coins++; //+1 coin
    returnString = "Obtained Coin, Coin Count is now " + to_string(coins) + " coins.\n";
    if (coins == 20){ //if Mario reaches 20 coins
        coins = 0; //reset coin count
        returnString = returnString + "20 Coins Reached! +1 Life! You now have " + to_string(lifes) + " lifes!\n";
        lifes++; //add one life
    }
    return returnString;
}

//getMushroom function
//function for when Mario gets a mushroom
string Mario::getMushroom(){
    if (powerLevel == 2){ //if Mario is already at Power Level 2, nothing happens 
        returnString = "Already At Power Level 2\n";
        return returnString;
    } else { //else Mario gains a power level
        powerLevel++; //+1 power level
        returnString = "Obtained Mushroom, Power Level is now " + to_string(powerLevel) + "!\n";
        return returnString;
    }
}

//randomMove function
//gets a random number to determine the next move for Mario
string Mario::randomMove(unsigned int seed, FileProcessor* myFP){
    srand(seed); //seed to get rand()
    int random = rand() % 4; //get a random number between 0-3
    if (random == 0){ //if number is 0 (25% chance) move DOWN
        returnString = "Mario will move down.\n";
        locationX = (locationX + 1) % myFP->worldSpecs[myFP->dimensions]; //if Mario reaches edge and moves further down, wrap up to the top
        return returnString;
    } else if (random == 1){ //if number is 1 (25% chance) move RIGHT
        returnString = "Mario will move right.\n";
        locationY = (locationY + 1) % myFP->worldSpecs[myFP->dimensions]; //if Mario reaches edge and moves further right, wrap to the left
        return returnString;
    } else if (random == 2){ //if number is 2 (25% chance) move UP
        returnString = "Mario will move up.\n";
        if (locationX == 0){
            locationX = locationX + myFP->worldSpecs[myFP->dimensions];
        }
        locationX = (locationX - 1) % myFP->worldSpecs[myFP->dimensions]; //if Mario reaches edge and moves further ip, wrap down to the bottom
        return returnString;
    } else { //if number is 3 (25% chance) move LEFT
        returnString = "Mario will move left.\n";
        if (locationY == 0){
            locationY = locationY + myFP->worldSpecs[myFP->dimensions];
        }
        locationY = (locationY - 1) % myFP->worldSpecs[myFP->dimensions]; //if Mario reaches edge and moves further left, wrap to the right
        return returnString;
    }
}

//defeatedEnemy function
//if Mario defeats an Enemy, +1 to the counter, if he reaches 7, +1 life
string Mario::defeatedEnemy(){
    enemiesDefeated++; //+1 enemy defeated
    returnString = "Defeated Enemy, Defeated Enemy Count: " + to_string(enemiesDefeated) + ".\n";

    if (enemiesDefeated == 7){ //if Mario reaches 7 enemies defeated
        returnString + returnString + "7 Enemies Defeated In Current Life. +1 Life.\n";
        enemiesDefeated = 0; //reset count
        lifes++; //+1 life
    }
    return returnString;
}

//resetDefeatedEnemy function
//if Mario dies or loses a life, reset the enemiesDefeated count to 0
string Mario::resetDefeatedEnemy(){
    returnString = "Mario Has Lost a Life. Resetting Enemies Defeated to 0\n";
    enemiesDefeated = 0; //reset count
    return returnString;
}