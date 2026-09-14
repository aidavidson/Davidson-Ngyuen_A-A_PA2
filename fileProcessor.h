#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H
#include "World.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class fileProcessor{
    private:
        std::string inputTxt;
        std::string outputTxt;
        std::string fullOutputBlock;
        int* arr;
    public:
        ~fileProcessor();
        fileProcessor(std::string input, std::string output);
        int processFile();
        int accessVal(int index); //for the 
        int outputFile();
        void printInteraction();
        void addToOutput(std::string txt);
};

#endif