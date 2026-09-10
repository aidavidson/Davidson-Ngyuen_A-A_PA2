#ifndef BOSS_H
#define BOSS_H
#include "World.h"
#include "Level.h"
#include "Mario.h"
#include <cstdlib>
#include <ctime>
class Boss{
    private:
        Mario character;
        Level currentLevel;
    public:
        Boss();
        ~Boss();    
        void fightBoss();
};

#endif