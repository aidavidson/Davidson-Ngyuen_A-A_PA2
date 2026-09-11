#include "World.h"
#include "Level.h"

//constructor
World::World(int L, int N) {
    this -> L = L;
    for (int i = 0; i < L; i++) { //new array of level pointers
        Level* newLevel = new Level(N);
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