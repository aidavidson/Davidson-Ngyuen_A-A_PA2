#include "Enemy.h"
#include "fileProcessor.h"
#include "World.h"
const int levelInd = 0;
const int dimenInd = 1;
const int numLiveInd = 2;
const int perCoinInd = 3;
const int perNothInd = 4;
const int perGoomInd = 5;
const int perKoopInd = 6;
const int perMushInd = 7;
const int gameStart = -1;

int main(int argc, char*argv[]){
    fileProcessor* newProcess = new fileProcessor(argv[1], argv[2]);

    int error = 0;
    error = newProcess->processFile();

    Mario m = Mario(newProcess->accessVal(numLiveInd));
    int currentLevel = -1;
    World w = World(newProcess->accessVal(levelInd), newProcess->accessVal(dimenInd), newProcess->accessVal(perCoinInd),newProcess->accessVal(perMushInd),newProcess->accessVal(perGoomInd), newProcess->accessVal(perKoopInd),newProcess->accessVal(perNothInd), currentLevel);

    if(error == 1){
        std::cout << "the input values for the input file are wrong" << std::endl;
        return 1;
    }
    int randomX = rand() % newProcess->accessVal(dimenInd);
    int randomY = rand() % newProcess->accessVal(dimenInd);
    w.setLevel();
    m.setX(randomX);
    m.setY(randomY);
    

    return 0;

}