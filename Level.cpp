#include "Level.h"

Level::Level() {
    this->n = n;
    grid = new char*[n]; //Array of char pointers

    //allocate memory for each row
    for (int i = 0; i < n; i++) {
        grid[i] = new char[n];
    }
};
Level::~Level() {};



