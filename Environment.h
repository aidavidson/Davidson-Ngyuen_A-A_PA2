#include "Level.h"
#include "Mario.h"
#include "Enemy.h"
#include "Collectible.h"

//what happens to mario when he interacts and maybe vice versa
class Environment {
    private:
        Enemy* Boss;
        Enemy* Goomba;
        Enemy* Koopa;
        Collectible* Coin;
        Collectible* Mushroom;
        bool warpPipe;
        Level* currentLevel = nullptr;

    public:
        Environment();
        ~Environment();
        void nextLevel();
        void gameOver();
        void setWarpPipe();
};