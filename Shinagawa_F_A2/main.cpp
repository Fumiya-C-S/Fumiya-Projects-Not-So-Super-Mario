#include "FileProcessor.h"
#include "World.h"
#include "Mario.h"

int main(int argc, char *argv[])
{
    World *myWorld = new World(argv[1]); //create world Class
    myWorld->playWorld(); //call playWorld function to play World
    delete myWorld; //garbage collect the World
    return 0;
}
