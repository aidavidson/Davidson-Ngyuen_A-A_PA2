#ifndef LEVEL_H
#define LEVEL_H
#include "Mario.h"

class Level {
    private:
        char** grid;
        bool warpPipe = false;
        bool complete = false;
        char c, m, g, k ,b ,x ,w ,n; //c: coin, m: mushroom, g: goomba, k: koopaTroopa, b: level boss, x: nothing, w: warp pipe, H: mario
    public:
        Level();
        Level(int n, int coins, int mushrooms, int goombas, int koopaTroopas, int nothing, bool lastLevel); //these are percentages and the bool, last level for the warp pipes
        ~Level();
};

#endif LEVEL_H
