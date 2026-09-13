#include "World.h"
#include "Level.h"

//constructor
World::World(int L, int N, int percentCoin,
     int percentMushroom, int percentGoombas,
     int percentKoopas, int percentNothing, int currentLevel) {
    this -> L = L;
    for (int i = 0; i < L; i++) { //new array of pointers to level objects
        Level* newLevel = new Level(N, percentCoin, percentMushroom, percentGoombas, percentKoopas, percentNothing);
        levels[i] = newLevel;
    }
    currentLevel = -1;
};

//destructor
World::~World() {
    for (int i = 0; i < L; i++) { //delete each arrays in array
        delete levels[i]; 
    }
    delete[] levels; //delete array
};

int World::getLevel(){
    return currentLevel;
}

int World::setLevel(){
    if(L <= currentLevel){
        return -1;
    }else if(L > currentLevel){
        currentLevel+=1;
    }
}