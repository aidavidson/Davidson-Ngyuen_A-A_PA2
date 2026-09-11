#ifndef WORLD_H
#define WORLD_H
#include "Level.h" //no s since Level only one object

class World {
    private:
        Level** levels = new Level*[L]; //pointer to an array of Levels, which need a pointer because it is an object
        int L; //number of levels
        int N; //size of Level
    public:
        World();
        ~World();

};


#endif