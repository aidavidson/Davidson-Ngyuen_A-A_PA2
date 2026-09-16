#include "Level.h"
#include "Mario.h"
#include "Enemy.h"
#include "Collectible.h"
#include "fileProcessor.h"

//what happens to mario when he interacts and maybe vice versa
class Environment {
    private:
        Mario* player;
        Enemy* Boss;
        Enemy* Goomba;
        Enemy* Koopa;
        Collectible* Coin;
        Collectible* Mushroom;
        bool gameComplete;
        Level* currentLevel = nullptr;
        int worldLength;

    public:

        Environment();
        Environment(Mario* mario, int worldLength);
        ~Environment();
        //25 percent chance for each direction
        std::string marioMove(fileProcessor* fp);
        //checks if mario won already
        bool isGameWon();
        void markGameWon();
        bool fightMario(Enemy* enemy);
        void marioCollect(Collectible* collectible, std::string which);
        Enemy* accessEnemy(std::string typeEnemy);
        Collectible* accessCollectible(std::string typeCollectible);

};