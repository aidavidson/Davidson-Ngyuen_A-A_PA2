#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H
#include "Mario.h"
#include <string>
class Collectible{
    private:
        Mario* mario;
        std::string type;
    public:
        Collectible(std::string type);
        ~Collectible();
        void collectCoin();
        void collectMushroom();
};
#endif;