#ifndef MARIO_H
#define MARIO_H

#include <string>

class Mario{
    private:
        int V;
        int coins;
        std::string powerLevel;
    public:
        std::string increasePower(std::string currentPower);
        
};

#endif