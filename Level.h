#ifndef LEVEL_H
#define LEVEL_H
#include "Mario.h"
#include "vector.h"
#include "World.h"
#include <cstdlib>
#include <ctime>

class Level {
    private:
        Vector* randomizedLocations;
        int* openSpots;
        char* letters;
        char** grid;
        bool warpPipe = false;
        bool complete = false;
        char c, m, g, k ,b ,x ,w ,n; //c: coin, m: mushroom, g: goomba, k: koopaTroopa, b: level boss, x: nothing, w: warp pipe, H: mario
        int currentLevel;
        int numLevels;;
    public:
        Level();
        Level(int N,int coins, int mushrooms, int goombas, int koopaTroopas, int nothing, int currentLevel, int numLevels);//these are percentages and the bool, last level for the warp pipes
        ~Level();
        void randomizeLevel();
        void populateGrid();
        std::string printLevel();
};

#endif LEVEL_H
