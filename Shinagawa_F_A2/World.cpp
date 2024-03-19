#include "World.h"

//default constructor
World::World(string outputFile){
    //set private variables initial state
    currentLevel = 0; 
    win == false;
    counter = 0;
    levelCompleted = false;

    outputFileName = outputFile;

    //initializing FileProcessor Class 
    myFP = new FileProcessor(outputFileName);
    myFP->processFile("input.txt"); //process File "input.txt" which holds all World Specifications

    //Initializing of other Classes
    myObjects = new Objects(); //Object Class that holds Koopa, Boss, Warp, Goomba
    myMario = new Mario(myFP); //Mario Class
    myLevels = new Level(myFP); //Levels Class
}

//default Destructor
World::~World(){
    //deletes initialized classes 
    delete myLevels;
    delete myMario;
    delete myObjects;
    delete myFP;
}

//startWorld function 
//Function that sets up all of the levels in the game
void World::startWorld(){

    textToOutput = "Level Layout:\n";

    //initializes levels 2D array with the amount of levels specified in fileProcessor
    levels = new char**[myFP->worldSpecs[myFP->levelCount]];

    //loop through each level and create the level
    for (int numLevel = 0; numLevel < myFP->worldSpecs[myFP->levelCount]; ++numLevel){
        //creates a level
        seed = static_cast<unsigned int>(time(NULL)) + numLevel; //gets a random seed for the random number generator used in createLevel()
        levels[numLevel] = myLevels->createLevel(myFP, seed); //calls createLevel in Level.cpp which fills in the positions with different objects

        textToOutput = textToOutput + "Level: " + to_string(numLevel) + "\n";

        //obtains a random location for Warp and Boss
        seed = static_cast<unsigned int>(time(NULL)) + numLevel + 1; //gets a random seed for random number generator used in warpRandom()
        myObjects->myWarp->warpRandom(seed, myFP); 
        seed = static_cast<unsigned int>(time(NULL)) + numLevel + 2; //gets a random seed for random number generator used in bossRandom()
        myObjects->myBoss->bossRandom(seed, myFP);

        //while the Boss position is the same exact position as warp, get another random position for Boss, until they are different
        while (myObjects->myWarp->warpLocationX == myObjects->myBoss->bossLocationX && myObjects->myWarp->warpLocationY == myObjects->myBoss->bossLocationY){
            seed = static_cast<unsigned int>(time(NULL)) + 1; //gets a random seed for random number generator
            myObjects->myBoss->bossRandom(seed, myFP); 
        }
        
        //if the level currently being created is NOT the final level, override the the current position with a warp block (last level does not have warp)
        if (numLevel + 1 != myFP->worldSpecs[myFP->levelCount]){
            levels[numLevel][myObjects->myWarp->warpLocationX][myObjects->myWarp->warpLocationY] = 'w';
        }
        //override the position to 'b' to indicate that the boss is there for that level
        levels[numLevel][myObjects->myBoss->bossLocationX][myObjects->myBoss->bossLocationY] = 'b';

        //Print the level with the characters describing what object is on which position
        for (int i = 0; i < myFP->worldSpecs[myFP->dimensions]; ++i){
            for(int j = 0; j < myFP->worldSpecs[myFP->dimensions]; ++j){
                    textToOutput = textToOutput + levels[numLevel][i][j] + " ";
            }
            textToOutput = textToOutput + "\n";
        }
        textToOutput = textToOutput + "==========================\n";
    }
}

//playWorld function
//this function runs the game logic
void World::playWorld(){
    //call startWorld() to create the levels
    startWorld();
    
    //game will start
    textToOutput = textToOutput + "GAME START\n";

    //Loops through each level untill all levels are completed or all lives are lost
    for (currentLevel; currentLevel < myFP->worldSpecs[myFP->levelCount]; ++currentLevel){
        textToOutput = textToOutput + "LEVEL " + to_string(currentLevel) + ": ";
        textToOutput += myMario->printLocation() + "\n"; //prints current location of Mario
        levelCompleted = false; //reset levelCompleted to false
        seed = static_cast<unsigned int>(time(NULL)) + counter + currentLevel; //get random seed for marioRandom()
        myMario->marioRandom(seed, myFP); //get a random starting location for Mario every time a new level starts

        //while the level has not been completed yet, keep looping
        //this loop will play through each step that Mario makes
        while (levelCompleted == false){
            //Output current Mario Stats
            textToOutput = textToOutput + "Mario is at Power Level " + to_string(myMario->powerLevel) + ".\n";
            textToOutput = textToOutput + "Mario has " + to_string(myMario->coins) + " coins.\n";
            textToOutput = textToOutput + "Mario has " + to_string(myMario->lifes) + " lives left\n";

            currentSpace = levels[currentLevel][myMario->locationX][myMario->locationY]; //set currentSpace to where Mario is currently at
            win = false;

            //if statement to check what object Mario has encountered at his current spot
            if (currentSpace == 'c'){ //if 'c' then Mario has obtained a Coin
                textToOutput = textToOutput + myMario->getCoin(); //call getCoin() function, which gives Mario 1 coin
                levels[currentLevel][myMario->locationX][myMario->locationY] = 'x'; //set the position to hold nothing after coin is obtained
            } 
            else if (currentSpace == 'm'){ //if 'm' then Mario has obtained a Mushroom
                textToOutput = textToOutput + myMario->getMushroom(); // call getMushroom() function, which upgrades Mario by 1 power level
                levels[currentLevel][myMario->locationX][myMario->locationY] = 'x'; //set the position to hold nothing after mushroom is obtained
            } 
            else if (currentSpace == 'w'){ //if 'w' then Mario will WARP to the next level
                textToOutput = textToOutput + "Mario found a warp pipe.\n";
                textToOutput = textToOutput + "Mario will WARP.\n";
                levelCompleted = true; //levelCompleted will be set to true, making us leave from the current while loop and move to the next level
            } 
            else if (currentSpace == 'b'){ //if 'b' then Mario will FIGHT the boss
                //while Mario has NOT won the battle
                while (win == false){ 
                    textToOutput = textToOutput + "Mario Won the battle against the Boss!\n";
                    seed = static_cast<unsigned int>(time(NULL)) + counter; //get a random seed for the random number that determines Mario Win/Loss
                    textToOutput = textToOutput + "BOSS BATTLE\n";
                    win = myObjects->myBoss->interact(seed); //interact returns a bool on whether or not Mario has Won or Lost the battle
                        if (win == false){ //if Mario did NOT win the battle
                            if (myMario->powerLevel == 2){ //if Mario has a Power Level of 2
                            myMario->powerLevel = myMario->powerLevel - 2; //he loses 2 powerlevels
                            textToOutput = textToOutput + "Mario's Power Level is lowered to " + to_string(myMario->powerLevel) + ".\n";
                            } 
                            else { //if he does not have 2 Power Level
                                if (myMario->lifes == 0){ //AND Mario has 0 lifes left
                                    printLevel(currentLevel);
                                    textToOutput = textToOutput + "You Lose :(\n";
                                    break; //break out of loop and game will END
                                } else { //if Mario still has lives
                                    myMario->lifes = myMario->lifes - 1; //Mario loses 1 life
                                    textToOutput = textToOutput + myMario->resetDefeatedEnemy(); //resets the amount of enemies defeated in currentl life
                                    //Mario loses a life and rematches the boss
                                    textToOutput = textToOutput + "Mario lost a life! Mario has " + to_string(myMario->lifes) + " lives left\n" + "REMATCH\n";

                                }
                            }
                            counter++;
                        } else { //else then Mario defeats the boss and +1 to the defeated enemy counter
                            textToOutput = textToOutput + "Mario Lost the battle against the Boss!\n";
                            textToOutput = textToOutput + myMario->defeatedEnemy(); 
                            levelCompleted = true; //set levelCompleted to true because boss is defeated
                        }
                }
            } 
            else if (currentSpace == 'k'){ //if 'k' then Mario will fight a Koopa
                seed = static_cast<unsigned int>(time(NULL)) + counter; //get a random seed for the random number that determines Mario Win/Loss
                textToOutput = textToOutput + "KOOPA BATTLE\n";
                win = myObjects->myKoopa->interact(seed); //interact returns a bool on whether or not Mario has Won or Lost the battle
                if (win == false){ //if Mario loses
                    textToOutput = textToOutput + "Mario Lost the battle against the Koopa!\n";
                    if (myMario->powerLevel == 2 || myMario->powerLevel == 1){ //AND Mario has Power Level 1 or 2
                        myMario->powerLevel = myMario->powerLevel - 1; //Mario loses 1 Power Level
                        textToOutput = textToOutput + "Mario's Power Level is lowered to " + to_string(myMario->powerLevel) + ".\n";
                    } else { //AND if Mario has 0 Power Level
                        if (myMario->lifes == 0){ //AND 0 Lifes Left
                            printLevel(currentLevel);
                            textToOutput = textToOutput + "You Lose :(\n";
                            break; //breaks out of loop and game will END
                        } else { //But has lifes left
                            myMario->lifes = myMario->lifes - 1; //Mario loses 1 life
                            textToOutput = textToOutput + myMario->resetDefeatedEnemy(); //resets counter for enemies defeated in one life
                            textToOutput = textToOutput + "Mario lost a life! Mario has " + to_string(myMario->lifes) + " lives left";
                        }
                        //if Mario loses and still is alive, Mario will move to the next spot, Koopa will stay in current spot
                    }
                    counter++; 
                } else { //if Mario WINS the battle
                    textToOutput = textToOutput + "Mario Won the battle against the Koopa!\n";
                    textToOutput = textToOutput + myMario->defeatedEnemy(); //+1 to the enemies defeated counter for this life
                    levels[currentLevel][myMario->locationX][myMario->locationY] = 'x'; //set the position to hold nothing after Koopa is defeated
                }
            } 
            else if (currentSpace == 'g'){
                seed = static_cast<unsigned int>(time(NULL)) + counter; //get a random seed for the random number that determines Mario Win/Loss
                textToOutput = textToOutput + "GOOMBA BATTLE\n";
                win = myObjects->myGoomba->interact(seed); //interact returns a bool on whether or not Mario has Won or Lost the battle
                if (win == false){ //if Mario LOSES
                    textToOutput = textToOutput + "Mario Lost the battle against the Goomba!\n";
                    if (myMario->powerLevel == 2 || myMario->powerLevel == 1){ //AND Mario has Power Level of 1 or 2
                        myMario->powerLevel = myMario->powerLevel - 1; //Mario loses 1 Power Level
                        textToOutput = textToOutput + "Mario's Power Level is lowered to " + to_string(myMario->powerLevel) + ".\n";
                    } else { //and has Power Level of 0
                        if (myMario->lifes == 0){ //and Mario has 0 lifes left
                            printLevel(currentLevel);
                            textToOutput = textToOutput + "You Lose :(\n";
                            break; //break through the loop and game ENDS
                        } else { //and Mario has lifes left
                            myMario->lifes = myMario->lifes - 1; //Mario loses a life
                            textToOutput = textToOutput + myMario->resetDefeatedEnemy(); //resets the counter on enemies defetead in one life
                            textToOutput = textToOutput + "Mario lost a life! Mario has " + to_string(myMario->lifes) + "lifes left\n";
                        }
                    }
                    counter++;
                } else { //if Mario WINS
                    textToOutput = textToOutput + "Mario Won the battle against the Goomba!\n";
                    textToOutput = textToOutput + myMario->defeatedEnemy(); //+1 to counter of enemies defeated in one life
                    levels[currentLevel][myMario->locationX][myMario->locationY] = 'x'; //set the position to hold nothing after Goomba is defeated
                }
            } else if (currentSpace == 'x'){ //if 'x' then Nothing Happens
                textToOutput = textToOutput + "Nothing Happened\n";

            }
            textToOutput = textToOutput + "Mario has " + to_string(myMario->lifes) + " lifes after this move.\n";
            textToOutput = textToOutput + "Mario has " + to_string(myMario->coins) + " coins after this move.\n";
            counter++;
            printLevel(currentLevel); //prints current level
            if (levelCompleted == false){ //if game/level has yet to be completed, then Mario moves randomly
                seed = static_cast<unsigned int>(time(NULL)) + counter; //gets a random seed for random number generator
                textToOutput = textToOutput + myMario->randomMove(seed, myFP); //randomly generetaed number will determine if Mario moves Up, Down, Left, or Right
            }
        }
    }

    textToOutput = textToOutput + "Mario made " + to_string(counter) + " moves this game.\n"; //print the number of moves made
    if (levelCompleted){ //if levelCompleted is True 
        textToOutput = textToOutput + "CONGRATS YOU WIN\n";
    } 

    myFP->outputToFile(textToOutput);
}

//printLevel function
//this function prints a specific Level
void World::printLevel(int numLevel){ //int numLevel specifies which level to print
    for (int i = 0; i < myFP->worldSpecs[myFP->dimensions]; ++i){
        for(int j = 0; j < myFP->worldSpecs[myFP->dimensions]; ++j){
            if (myMario->locationX == i && myMario->locationY == j){ //if printing the location Mario is set at, then print 'H' instead of what is stored in the level
                textToOutput = textToOutput + 'H' + " ";
            } else { //else print what is stored in the level
                textToOutput = textToOutput + levels[numLevel][i][j] + " ";
            }
        }
        textToOutput = textToOutput + "\n";
    }

    textToOutput = textToOutput +  "==========================\n";
}

//printWorld function
//prints all of the levels
void World::printWorld(){
    for (int numLevel = 0; numLevel < myFP->worldSpecs[myFP->levelCount]; ++numLevel){ //loops through all of the levels
        for (int i = 0; i < myFP->worldSpecs[myFP->dimensions]; ++i){ //loops through all of the columns of the level
            for(int j = 0; j < myFP->worldSpecs[myFP->dimensions]; ++j){ //loops through each row of the column
                if (myMario->locationX == i && myMario->locationY == j){ //if printing the location Mario is set at, then print 'H' instead of what is stored in the level
                    textToOutput = textToOutput + 'H' + " ";
                } else { //else print what is stored in the level
                    textToOutput = textToOutput + levels[numLevel][i][j] + " ";
                }
            }
            textToOutput = textToOutput + "\n";
        }
            textToOutput = textToOutput +  "==========================\n";
    }   
}

