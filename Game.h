#ifndef GAME_H
#define GAME_H
#include "fileProcessor.h"
#include "Environment.h"

class Game{
    private:
        fileProcessor* instancefp;
        Mario* mario;
        World world;
        Vector marioPos;
        Environment marioImpacts;
        int error;
        const int levelInd = 0;
        const int dimenInd = 1;
        const int numLiveInd = 2;
        const int perCoinInd = 3;
        const int perNothInd = 4;
        const int perGoomInd = 5;
        const int perKoopInd = 6;
        const int perMushInd = 7;
        const int gameStart = -1;
        bool wonBattle;
    public:
        Game(fileProcessor* fp);
        int initializeGame();
        void repeatedAction();
        std::string marioPosText();
        std::string gameText();
        std::string finishGameTxt();

};

#endif