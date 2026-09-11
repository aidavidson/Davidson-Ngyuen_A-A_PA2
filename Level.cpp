#include "Level.h"

Level::Level(int N, int coins, int mushrooms, int goombas, int koopaTroopas, int nothing) {
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

    populateLevel(n);
}

Level::~Level() {
    for (int i = 0; i < n; i++) {
        delete[] grid[i]; //deallocate the outer arrays
    }
    delete[] grid; //deallocate inner arrays
    //delete each element of matrix
}

void Level::populateLevel(){
    int Length = (n*n);
    int array[n][n];
    populateArray(n);
    int i;
        for(int j = 0; j < 5; j+=0){
            if(openSpots[j] != 0){
                srand(time(0));
                int randomR = (rand() % (n-1)) + 1;
                int randomC = (rand() % (n-1)) + 1;
                if(array[randomR][randomC] == 1){
                    // do nothing since the space is taken
                }else{
                    // space hasn't been taken therefore take it
                    grid[randomR][randomC] = letters[j];
                    openSpots[j] -= 1;
                }
            }else{
                j++;
            }
            
        }  
}




void populateArray(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[]
        }
    }
}