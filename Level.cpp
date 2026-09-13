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
    letters[4] = 'n';
    
    n = N; //level size
    grid = new char*[n]; //Array of char pointers

    //allocate memory for each row
    for (int i = 0; i < n; i++) {
        grid[i] = new char[n]; //new array for each first index of the array of pointers
    }

    this -> warpPipe = false; //initialize variables
    this -> complete = false; //initialize variables

    randomizeLevel();
    populateGrid();
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

void Level::randomizeLevel(){
    randomizedLocations = Vector::populateList(n);
    int numFound;
    int j = 0;
    for(int i = 0; i< n*n-numFound; i++){
        
        srand(time(0));
        int randInd = rand() % (n*n-numFound);

        if(randomizedLocations[randInd].getChosen() == false){

            randomizedLocations[randInd].setChosen(true);

            Vector temp;

            if(openSpots[j] != 0){
                randomizedLocations[randInd].setType(letters[j]);
            }else{
                j++;
            }
            temp = randomizedLocations[randInd];

            randomizedLocations[randInd] = randomizedLocations[n*n-1];

            randomizedLocations[n*n-1] = temp;

            numFound++;
            
        }
    }   
}
void Level::populateGrid(){
    for(int i = 0; i < n*n-1; i++){
        grid[randomizedLocations[i].getX()][randomizedLocations[i].getY()] = randomizedLocations[i].getType();
    }
    if(currentLevel != (numLevels-1)){
        int randomX = rand() % n;
        int randomY = rand() % n;

        grid[randomX][randomY] = 'w';
    }

    int randomX = rand() % n;
    int randomY = rand() % n;

    grid[randomX][randomY] = 'b';
    
}

std::string Level::printLevel(){
    std::string print;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            print += grid[i][j];
            print += " ";
        }
        print += "\n";
    }
    print += "==========";
}
