#ifndef WORLD_H
#define WORLD_H

#include "Mario.h" 
#include "FileProcessor.h"
#include "Level.h"
#include "Objects.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//World Class
class World{
    public:
        World(string outputFile); //default constructor
        ~World(); //default destructor

        //core functions
        void startWorld(); //create and print levels without Mario
        void playWorld(); //start to play the game, includes game functions 
        void printWorld(); //print all levels
        void printLevel(int numLevel); //print specific level

    private:
        //initialize FileProcessor, Mario, Level, and Objects class
        FileProcessor *myFP;
        Mario *myMario;
        Level *myLevels;
        Objects *myObjects;

        int currentLevel; //integer that holds the current level Mario is on
        char currentSpace; //the object char that is held within the level that mario is on currently
        char*** levels; //3D array of levels, that contain the rows and columns of levels
        char** world; //2D array that contain the rows and columns of the level
        bool levelCompleted; //boolean on whether or not Mario has completed the specific level
        bool win; //boolean on whether or not Mario won the battle against Goomba/Koopa/Boss
        int counter; //counter on how many moves Mario has made
        unsigned int seed; //seed for rand() operation

        string outputFileName;
        string textToOutput;
};

#endif