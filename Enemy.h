#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include <cstdlib>
#include <ctime>
#include "Mario.h"
class Enemy{
    private:
        Mario* mario;
        std::string type;
        int percentWin;
        int numDecrease;
        bool loss;

    public:
        Enemy(std::string type, int percentWin,int numDecrease);
        ~Enemy();
        void fightMario();        
};

#endif