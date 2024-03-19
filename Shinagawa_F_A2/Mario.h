#ifndef MARIO_H
#define MARIO_H

#include "FileProcessor.h"
#include <iostream>
#include <cstdlib>
#include <random>
using namespace std;

//Mario Class
class Mario{
    public:
        Mario(FileProcessor* myFP);  //default constructor
        ~Mario(); //defauly destructor

        //core functions
        string printLocation(); //print current Mario location
        string randomMove(unsigned int seed, FileProcessor* myFP); //randomly move either Up, Down, Right, or Left
        string getCoin(); //obtain a coin
        string getMushroom(); //obtain a mushroom
        void marioRandom(unsigned int seed, FileProcessor* myFP); //get a random starting point for Mario
        string defeatedEnemy(); //+1 to counter for enemies defeated in one life
        string resetDefeatedEnemy(); //resets enemies defeated if Mario loses a life

        //public member variables
        int coins; //current coin count
        int powerLevel; //current powerLevel count
        int lifes; //current life count
        int locationX; //current location on X axis
        int locationY; //current location on Y axis
        int enemiesDefeated; //current enemies defeated count
        string returnString;
};

#endif