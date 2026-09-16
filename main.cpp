#include "fileProcessor.h"
#include "World.h"
#include "Game.h"
#include <iostream>

int main(int argc, char*argv[]){
    if (argc != 3) {
        std::cout << "Not 3 arguments in command line." << std::endl;
        return 1;
    }
    
    //creates a file processor object to use the text files to implement the game
    fileProcessor* newProcess = new fileProcessor(argv[1], argv[2]);
    srand(time(0));
    
    Game develop = Game(newProcess); 
    
    develop.repeatedAction();
    
    delete newProcess;
    
    return 0;

}
