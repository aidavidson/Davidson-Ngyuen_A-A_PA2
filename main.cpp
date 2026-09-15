#include "fileProcessor.h"
#include "World.h"
#include "Game.h"


int main(int argc, char*argv[]){
    //creates a file processor object to use the text files to implement the game
    fileProcessor* newProcess = new fileProcessor(argv[1], argv[2]);
    Game develop = Game(newProcess); 
    develop.repeatedAction();
    //newProcess->~fileProcessor();
    delete newProcess;
    //develop.~Game();

    return 0;

}
