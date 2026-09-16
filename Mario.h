#ifndef MARIO_H
#define MARIO_H

#include <string>

class Mario{
    private:
        // total lives
        int V;
        // number of coins
        int coins;
        // current enemies defeated in a row
        int enemiesDefeated;
        // position vector
        // x position
        int x;
        // y position
        int y;
        //current power level P0 P1 P2
        int powerLevel;
        // the different power level possibilities
        int powerLevels[3] = {0, 1, 2};
        // whether or not the enemy mario is fighting lost or not
        bool beatEnemy;
    public:
        //constructors/destructors of the mario class
        Mario(int lives);

        //destructor
        ~Mario();
        
        // modifies the power of mario
        void increasePower(int currentPower);
        void decreasePower(int currentPower,int amount);
        //sets whether the enemy was beat or not
        void setBeatEnemy(bool tf);
        // allows you to set the amount of defeated enemies
        void increaseDefeatedEnemies();
        // gets the power so the decrease power works properly
        int getPower();
        // gets the amount of lives mario currently has in the game
        int getLives();
        // decrements the amount of lives mario has
        void loseLives();
        // increments the amount of lives mario has
        void gainLives();
        // allows you to get the amount of defeated enemies in a row
        int getEnemiesDefeated();

        // setting position values for mario
        void setX(int val);
        void setY(int val);
        int getX();
        int getY();

        void collectCoin();
        int getCoins();
    };

#endif