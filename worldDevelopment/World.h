#ifndef WORLD_H
#define WORLD_H
#include "Level.h" //no s since Level only one object

class World {
    private:
        Level** levels = new Level*[L]; //pointer to an array of Levels, which need a pointer because it is an object
        int L; //number of levels
        int currentLevel;
    public:
        World(int L, int N, int percentCoin, 
        int percentMushroom, int percentGoombas,
        int percentKoopas, int percentNothing, int currentLevel);
        World();
        ~World();
        int setLevel();
        int getLevel();
        char** getLevelgrid(int currentLevel);
        void setLevelGridElement(char c, int x , int y);  
        bool isCurrentLevelComplete();

};


#endif