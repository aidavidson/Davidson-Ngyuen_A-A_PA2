#ifndef LEVEL_H
#define LEVEL_H
#include "Mario.h"
#include <cstdlib>
#include <ctime>

class Level {
    private:
        int* openSpots;
        char* letters;
        char** grid;
        bool warpPipe = false;
        bool complete = false;
        char c, m, g, k ,b ,x ,w ,n; //c: coin, m: mushroom, g: goomba, k: koopaTroopa, b: level boss, x: nothing, w: warp pipe, H: mario
    public:
        Level();
        Level(int N,int coins, int mushrooms, int goombas, int koopaTroopas, int nothing);//these are percentages and the bool, last level for the warp pipes
        ~Level();
        void populateLevel();
};

#endif LEVEL_H
