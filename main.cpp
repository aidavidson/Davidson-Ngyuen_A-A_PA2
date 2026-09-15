#include "fileProcessor.h"
#include "World.h"
#include "Game.h"


int main(int argc, char*argv[]){
    if (argc != 3) {
        std::cout << "Not 3 arguments in command line." << std::endl;
    }
    //creates a file processor object to use the text files to implement the game
    fileProcessor* newProcess = new fileProcessor(argv[1], argv[2]);
    srand(time(0));
    Game develop = Game(newProcess); 
    develop.repeatedAction();
    //newProcess->~fileProcessor();
    delete newProcess;
    //develop.~Game();

    return 0;

}
