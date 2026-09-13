#ifndef LEVEL_H
#define LEVEL_H
#include "Mario.h"
#include "vector.h"
#include <cstdlib>
#include <ctime>

class Level {
    private:
        // the list which is populated with the vector objects with corresponding positions on grid
        Vector* randomizedLocations;
        // an int array containing the number of open spots for each type of object
        int* openSpots;
        // a character array which contains all the different types of objects mario would land on
        char* letters;
        // the grid for each level
        char** grid;
        //not sure if needed
        bool warpPipe = false;
        // whether mario has defeated the level or not
        bool complete = false;
        //not sure if needed
        bool lastLevel = false;
        // not sure if needed
        char c, m, g, k ,b ,x ,w ,n; //c: coin, m: mushroom, g: goomba, k: koopaTroopa, b: level boss, x: nothing, w: warp pipe, H: mario
        // tests if the current level is the last one
        int currentLevel;
        // ensures that you cant get a level higher than max levels
        int numLevels;
    public:
        //constructors/destructors
        //not sure if needed
        Level();
        //main constructor
        Level(int N,int coins, int mushrooms, int goombas, int koopaTroopas, int nothing, int currentLevel, int numLevels);//these are percentages and the bool, last level for the warp pipes
        ~Level();
        //not sure if needed
        Level(int N, int percentCoin, int percentMushroom, int percentGoombas, int percentKoopas, int percentNothing);
        //randomizes the positions of each of the objects
        void randomizeLevel();
        //populates the grid with the objects
        void populateGrid();
        //prints the level out for output
        std::string printLevel();
        // not sure if needed
        //checks if the level is complete or not
        bool isComplete();
        // not sure if needed
        //checks if the level should have a warp pipe
        bool hasWarpPipe();
        //
        void changeGridPos();
};

#endif
