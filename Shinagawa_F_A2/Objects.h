#ifndef OBJECTS_H
#define OBJECTS_H

#include <iostream>
#include <cstdlib>
#include "Mario.h"
#include "Warp.h"
#include "Boss.h"
#include "Goomba.h"
#include "Koopa.h"
using namespace std;

//Objects Class
class Objects{
    public:
        Objects(); //default constructor
        ~Objects(); //default destructor

        //core function
        bool interact(); //interact function that will be inherited by child classes (Koopa, Goomba, Boss)

        //initialize children classes of Objects
        Warp *myWarp;
        Boss *myBoss;
        Goomba *myGoomba;
        Koopa *myKoopa;
};

#endif