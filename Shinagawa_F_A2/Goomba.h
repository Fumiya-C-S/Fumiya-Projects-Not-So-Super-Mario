#ifndef GOOMBA_H
#define GOOMBA_H

using namespace std;
#include "Mario.h"
#include <iostream>

//forward declaration of Objects
class Objects;

//Goomba Class
class Goomba{
    public:
        Goomba(); //default constructor
        ~Goomba(); //default destructor

        //core functions
        virtual bool interact(unsigned int seed); //override interact class from Objects
};

#endif