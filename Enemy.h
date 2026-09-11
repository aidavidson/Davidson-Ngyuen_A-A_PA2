#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include <cstdlib>
#include <ctime>
#include "Mario.h"

class Enemy{
    private:
        Mario mario;
        std::string type;
        int winOrLoss;
        bool dead;
    public:
        Enemy(std::string type);
        ~Enemy();
        int checkEnemiesDefeated();
        void battleEnemy();

};

#endif