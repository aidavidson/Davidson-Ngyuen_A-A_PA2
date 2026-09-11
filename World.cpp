#include "World.h"
#include "Level.h"

//constructor
World::World() {
    this -> L = L;
    this -> N = N;
    for (int i = 0; i < L; i++) { //new array of level pointers
        Level* newLevel;
        levels[i] = newLevel;
    }
};

//destructor
World::~World() {
    for (int i = 0; i < L; i++) {
        delete levels[i];
    }
    delete[] levels;
};