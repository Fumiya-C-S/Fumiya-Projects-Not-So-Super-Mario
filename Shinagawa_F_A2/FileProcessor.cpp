#include "FileProcessor.h"

//default constructor
FileProcessor::FileProcessor(string outputFileName){
    outputFile = outputFileName;
}

//defualt destructor
FileProcessor::~FileProcessor(){}

//processFile function
//proccesses file and gets world specifications from "input.txt"
void FileProcessor::processFile(string inputFile){
    //open file 
    ifstream inFile;
    inFile.open(inputFile);

    if(inFile.is_open()){ //if file is open
        int i = 0;
        while(getline(inFile, worldSpec)){ //until all lines are read
            int value = stoi(worldSpec); //change the string obtained into a integer
            worldSpecs[i] = value; //store the integer into the specified location in order into the array
            i++; //increment i to add next specification to next spot in array
        }
    }
    inFile.close(); //close the file stream
}

void FileProcessor::outputToFile(string text){
    ofstream outFile;
    outFile.open(outputFile);

    if(outFile.is_open()){
        outFile << text << endl;
    }

    outFile.close(); //close the file stream
}