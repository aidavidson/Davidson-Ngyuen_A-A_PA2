#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H
#include "Mario.h"
#include <string>
class Collectible{
    private:
        // the pointer which allows the mario from main to be referenced in this class
        Mario* player;
        // the type of object mario collides with
        std::string type;
    public:
        //constructor/destructor
        Collectible(std::string type, Mario* mario);
        ~Collectible();
        // increases marios coins
        std::string getName();
        void collectCoin();
        // increases marios Power
        void collectMushroom();
        // if mario collides with warp pipe enter new level
        void warpPipe();
};
#endif