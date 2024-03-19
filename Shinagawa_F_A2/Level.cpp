#include "Level.h"

//default constructor
Level::Level(FileProcessor* myFP){
    cols = myFP->worldSpecs[myFP->dimensions];
    rows = myFP->worldSpecs[myFP->dimensions];
}

//default destructor
Level::~Level(){}

//createLevel function
//fills in all the slots of a level randomly
char** Level::createLevel(FileProcessor* myFP, unsigned int seed){
    world = new char*[cols]; //initialize number of columns 
    for (int i = 0; i < cols; ++i){
        world[i] = new char[rows]; //initialize nooumber of rows
    }

    srand(seed); //get a random seed
    int random; //initialize random to store random number betwee 0-99

    for (int i = 0; i < myFP->worldSpecs[myFP->dimensions]; ++i){ //for each column
        for(int j = 0; j < myFP->worldSpecs[myFP->dimensions]; ++j){ //for each row
            random = rand() % 100; //get a random number 0-99
            if (random >=0 && random < myFP->worldSpecs[myFP->percentageCoin]){ //if the random number is between 0-percentage of coin, then fill that slot with 'c' (Ex. if percentageCoin == 20, 0-19 will result in the slot being filled with 'c')
                world[i][j] = 'c';
            } else if (random >= myFP->worldSpecs[myFP->percentageCoin] && random < myFP->worldSpecs[myFP->percentageNothing] + myFP->worldSpecs[myFP->percentageCoin]){ //if random number is between percentageCoin and percentageCoin + percentageNothing, then fill it with 'x' (nothing)
                world[i][j] = 'x';
            } else if (random >= myFP->worldSpecs[myFP->percentageNothing] + myFP->worldSpecs[myFP->percentageCoin] && random < myFP->worldSpecs[myFP->percentageNothing] + myFP->worldSpecs[myFP->percentageCoin] + myFP->worldSpecs[myFP->percentageGoomb]){ //if random number is between percentageCoin + percentageNothing and percentageCoin + percentageNothing + percentageGoomb then fill it with "g" (goomba)
                world[i][j] = 'g';
            } else if (random >= myFP->worldSpecs[myFP->percentageNothing] + myFP->worldSpecs[myFP->percentageCoin] + myFP->worldSpecs[myFP->percentageGoomb] && random < myFP->worldSpecs[myFP->percentageNothing] + myFP->worldSpecs[myFP->percentageCoin] + myFP->worldSpecs[myFP->percentageGoomb] + myFP->worldSpecs[myFP->percentageKoopa]){ //if random number is between percentageCoin + percentageNothing + percentageGoomb and percentageCoin + percentageNothing + percentageGoomb + percentageKoopa, then fill it with 'k' (Koopa)
                world[i][j] = 'k';
            } else if (random >= myFP->worldSpecs[myFP->percentageNothing] + myFP->worldSpecs[myFP->percentageCoin] + myFP->worldSpecs[myFP->percentageGoomb] + myFP->worldSpecs[myFP->percentageKoopa] && random <= 99){ //if random number is between percentageCoin + percentageNothing + percentageGoomb + percentageKoopa and 99, then fill it with 'm' (Mushroom)
                world[i][j] = 'm';
            }
        }
    }
    return world; //return the completed level
}
