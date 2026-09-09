#ifndef MARIO_H
#define MARIO_H

#include <string>

class Mario{
    private:
        int V;
        int coins;
        std::string powerLevel;
        std::string* powerLevels;
    public:
        Mario(int lives);
        ~Mario();
        std::string increasePower(std::string currentPower);
        std::string decreasePower(std::string currentPower);
        std::string modPower(std::string object);
};

#endif