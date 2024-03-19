#ifndef KOOPA_H
#define KOOPA_H

using namespace std;
#include <iostream>
#include "Mario.h"

//forward declaration of Objects
class Objects;

//Koopa Class
class Koopa{
    public:
        Koopa(); //default constructor
        ~Koopa(); //defauly destructor

        //core functions
        virtual bool interact(unsigned int seed); //override interact class from Objects
};

#endif