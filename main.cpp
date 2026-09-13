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
    //creates a file processor object to use the text files to implement the game
    fileProcessor* newProcess = new fileProcessor(argv[1], argv[2]);

    // ***** Possible Game Class *****
    // checks if
    int error = 0;
    error = newProcess->processFile();
    if(error == 1){
        std::cout << "the input values for the input file are wrong" << std::endl;
        return 1;
    }
    //creates a mario object to use for the whole game
    Mario* m = new Mario(newProcess->accessVal(numLiveInd));
    // starts with -1 for level so when it increments to level 0 
    //in world it doesn't skip a level
    int currentLevel = -1;

    //creates a world object which populates with all the level data
    World w = World(newProcess->accessVal(levelInd), newProcess->accessVal(dimenInd), newProcess->accessVal(perCoinInd),newProcess->accessVal(perMushInd),newProcess->accessVal(perGoomInd), newProcess->accessVal(perKoopInd),newProcess->accessVal(perNothInd), currentLevel);
    
    //finds random indexes for mario in a new level --> should be in a class idk where for now
    int randomX = rand() % newProcess->accessVal(dimenInd);
    int randomY = rand() % newProcess->accessVal(dimenInd);
    //sets the current level from -1 -> 0
    w.setLevel();
    //sets marios position in the level
    m->setX(randomX);
    m->setY(randomY); 

    Environment marioImpacts = Environment(m);
    //did mario lose or win if not continue repeating
    while(m->getLives() != 0 || marioImpacts.isGameWon() == false){
        if(w.isCurrentLevelComplete() == true){
            marioImpacts.marioMove();
        }
    }
    
    //************************** */
    return 0;

}