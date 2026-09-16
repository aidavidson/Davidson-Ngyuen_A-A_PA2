#include "Level.h"

Level::Level(int N, int coins, int mushrooms, int goombas, int koopaTroopas, int nothing, int currentLevel, int numLevels) {
    openSpots = new int[5];
    openSpots[0] = coins;
    openSpots[1] = mushrooms;
    openSpots[2] = goombas;
    openSpots[3] = koopaTroopas;
    openSpots[4] = nothing;
    letters = new char[5];
    letters[0] = 'c';
    letters[1] = 'm';
    letters[2] = 'g';
    letters[3] = 'k';
    letters[4] = 'x';
    
    this->currentLevel = currentLevel;
    this->numLevels = numLevels;
    n = N; //level size
    grid = new char*[n]; //Array of char pointers

    //allocate memory for each row
    for (int i = 0; i < n; i++) {
        grid[i] = new char[n]; //new array for each first index of the array of pointers
    }
    randomizeLevel();
    populateGrid();

    complete = false;
}

Level::~Level() {
    for (int i = 0; i < n; i++) {
        delete[] grid[i]; //deallocate the outer arrays
    }
    delete[] grid; //deallocate inner arrays
    //delete each element of matrix
    delete[] openSpots;
    delete[] letters;
    delete[] randomizedLocations;
}

bool Level::isComplete() {
    return complete;
}

bool Level::hasWarpPipe() {
    return warpPipe;
}

void Level::randomizeLevel() {
    randomizedLocations = Vector::populateList(n);
    int j = 0;

    for (int i = 0; i < n * n; i++) {
        int remaining = n * n - i;
        int randInd = rand() % remaining;

        while (j < 5 && openSpots[j] <= 0) {
                j++;
            }

        char tile = 'x'; // Empty if all counts are exhausted.

        if (j < 5) {
            tile = letters[j];
            openSpots[j]--;
        }

        randomizedLocations[randInd].setType(tile);
        randomizedLocations[randInd].setChosen(true);

        Vector temp = randomizedLocations[randInd];
        randomizedLocations[randInd] =
            randomizedLocations[remaining - 1];
        randomizedLocations[remaining - 1] = temp;
    }
}

void Level::populateGrid() {
    for (int i = 0; i < n * n; i++) {
        int row = randomizedLocations[i].getX();
        int col = randomizedLocations[i].getY();

        grid[row][col] = randomizedLocations[i].getType();
    }

    int bossRow = rand() % n;
    int bossCol = rand() % n;
    grid[bossRow][bossCol] = 'b';

    if (currentLevel < numLevels - 1) {
        int warpRow;
        int warpCol;

        do {
            warpRow = rand() % n;
            warpCol = rand() % n;
        } while (warpRow == bossRow && warpCol == bossCol);

        grid[warpRow][warpCol] = 'w';
    }
}

std::string Level::printLevel(){
    std::string print;
    print += "\n==========\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            print += grid[i][j];
            print += " ";
        }
        print += "\n";
    }
    print += "==========\n";
    return print;
}


void Level::changeGridChar(char letter, int x, int y){
    grid[x][y] = letter;
}

char** Level::returnGrid(){
    return grid;
}