#include "Objects.h"

Objects::Objects(){
    //initialize all objects
    myWarp = new Warp();
    myBoss = new Boss();
    myGoomba = new Goomba();
    myKoopa = new Koopa();
}

Objects::~Objects(){
    //garbage collect all objects
    delete myKoopa;
    delete myGoomba;
    delete myBoss;
    delete myWarp;
}