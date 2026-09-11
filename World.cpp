#include "World.h"
#include "Level.h"

//constructor
World::World(int L, int N, int percentCoin,
     int percentMushroom, int percentGoombas,
     int percentKoopas, int percentNothing) {
    this -> L = L;
    for (int i = 0; i < L; i++) { //new array of pointers to level objects
        Level* newLevel = new Level(N, percentCoin, percentMushroom, percentGoombas, percentKoopas, percentNothing);
        levels[i] = newLevel;
    }
};

//destructor
World::~World() {
    for (int i = 0; i < L; i++) { //delete each arrays in array
        delete levels[i]; 
    }
    delete[] levels; //delete array
};