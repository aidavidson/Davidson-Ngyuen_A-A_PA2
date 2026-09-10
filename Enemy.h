#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include "Mario.h"
class Enemy{
    private:
        Mario mario;
        std::string type;
        int winOrLoss;
        bool dead;
    public:
        Enemy();
        ~Enemy();
        void checkEnemiesDefeated();
        void battleEnemy();

};

#endif