#include "Environment.h" 
#include "Level.h"

Environment::Environment(Mario* mario) {
    //these are the different objects mario can collide with and their properties show 
    //the possiblity of winning and how much power level they take away
    player = mario;
    Boss = new Enemy("Boss", 50, 2, player);
    Goomba = new Enemy("Goomba", 80, 1, player);
    Koopa = new Enemy("Koopa", 65, 1, player);
    Coin = new Collectible("Coin", player);
    Mushroom = new Collectible("Mushroom", player);
    gameComplete = false;
}

Environment::~Environment() {
    delete Boss;
    delete Goomba;
    delete Koopa;
    delete Coin;
    delete Mushroom;
}

void Environment::nextLevel(){
    if(currentLevel != nullptr && currentLevel->isComplete()) {
        //move on to next level
    }
}

void Environment::gameOver(){
    
}

bool Environment::isGameWon(){
    return gameComplete;
}
