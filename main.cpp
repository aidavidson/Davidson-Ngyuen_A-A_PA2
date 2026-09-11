#include "Enemy.h"
#include "fileProcessor.h"
const int levelInd = 0;
const int dimenInd = 1;
const int numLiveInd = 2;
const int perCoinInd = 3;
const int perNothInd = 4;
const int perGoomInd = 5;
const int perKoopInd = 6;
const int perMushInd = 7;

int main(int argc, char*argv[] ){
    fileProcessor* newProcess = new fileProcessor(argv[1], argv[2]);
    Mario* m = new Mario(newProcess->accessVal(numLiveInd));
    
    int error = 0;
    error = newProcess->processFile();
    if(error == 1){
        std::cout << "the input values for the input file are wrong" << std::endl;
        return 1;
    }

    return 0;

}