#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <fstream>

using namespace std;

//FileProcessor Class
class FileProcessor{
    public:
        FileProcessor(string outputFileName); //default constructor
        ~FileProcessor(); //default destructor
        
        //core functions
        void processFile(string inputFile); //pass in a string which is the name of the input file containing the specs of the world
        void outputToFile(string text);

        string worldSpec; //string to store the line obtained from File
        int worldSpecs[8]; //array of which will store the world specifications

        //corresponding values to position in worldSpecs array
        int levelCount = 0; //levelCount is first integer stored in array
        int dimensions = 1; //dimensions is second interger stored in array
        int initialLives = 2; //initialLives is third interger stored in array
        int percentageCoin = 3; //percentageCoin is fourth
        int percentageNothing = 4; //percentageNothing is fifth
        int percentageGoomb = 5; //percentageGoomb is sixth
        int percentageKoopa = 6; //percentageKoopa is seventh
        int percentageMushroom = 7; //percentageMushroom is eighth

        string outputFile;
};

#endif