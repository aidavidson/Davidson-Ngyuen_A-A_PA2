#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class fileProcessor{
    private:
        std::string inputTxt;
        std::string outputTxt;
        int* arr;
    public:
        ~fileProcessor();
        fileProcessor(std::string input, std::string output);
        int processFile();
        int accessVal(int index);
};

#endif