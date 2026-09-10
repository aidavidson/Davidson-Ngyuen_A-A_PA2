#ifndef MARIO_H
#define MARIO_H

#include <string>

class Mario{
    private:
        int V;
        int coins;
        int enemiesDefeated;
        int x;
        int y;
        int powerLevel;
        int powerLevels[3] = {0, 1, 2};
    public:
        Mario(int lives);
        Mario();
        ~Mario();
        int increasePower(int currentPower);
        int decreasePower(int currentPower);
        void setDefeatedEnemies();
        int getPower();
        int getLives();
        void loseLives();
        void gainLives();
        int getEnemiesDefeated();
        void setX();
        void setY();
    };

#endif