#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include <cstdlib>
#include <ctime>
#include "Mario.h"
class Enemy{
    private:
        Mario* player; //pointer move across classes, only 1 mario
        std::string type;
        int percentWin;
        int numDecrease;
        bool loss;

    public:
        Enemy(std::string type, int percentWin,int numDecrease, Mario* mario);
        ~Enemy();
        void fightMario();        
};

#endif