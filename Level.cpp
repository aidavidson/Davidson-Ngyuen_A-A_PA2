#include "Level.h"

Level::Level(int N) {
    n = N; //level size
    grid = new char*[n]; //Array of char pointers

    //allocate memory for each row
    for (int i = 0; i < n; i++) {
        grid[i] = new char[n]; //new array for each first index of the array of pointers
    }
};
Level::~Level() {
    for (int i = 0; i < n; i++) {
        delete[] grid[i]; //deallocate the outer arrays
    }
    delete[] grid; //deallocate inner arrays
    //delete each element of matrix
};



