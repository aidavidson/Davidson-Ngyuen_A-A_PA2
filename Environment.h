#include "Level.h"
#include "Mario.h"
#include "Enemy.h"
#include "Collectible.h"

class Environment {
    private:
        Enemy* Boss;
        Enemy* Goomba;
        Enemy* Koopa;
        Collectible* Coin;
        Collectible* Mushroom;
        bool warpPipe;

    public:
        Environment();
        ~Environment();
        void nextLevel();
        void gameOver();
        void setWarpPipe();
};