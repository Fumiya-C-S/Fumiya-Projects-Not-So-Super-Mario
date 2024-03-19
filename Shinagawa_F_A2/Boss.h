#ifndef BOSS_H
#define BOSS_H

#include <iostream>
#include "Mario.h"
#include "FileProcessor.h"
using namespace std;

//forward declaration of Objects
class Objects;

//Boss Class
class Boss{
    public:
        Boss();
        ~Boss();

        //core functions
        virtual bool interact(unsigned int seed); //override interact class from Objects
        void bossRandom(unsigned int seed, FileProcessor* myFP); //function to get a random coordinate for boss 

        int bossLocationX; //coordinate on X axis for boss
        int bossLocationY; //coordinate on Y axis for boss
};

#endif