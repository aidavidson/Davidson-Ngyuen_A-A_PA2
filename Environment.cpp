#include "Environment.h" 
#include "Level.h"

Environment::Environment() {
    //have mario move
    //deal with 5 specific cases for that level
    //then, for the specific rows, we might need level, but how to declare it?
    Boss = new Enemy("Boss", 50, 2);
    Goomba = new Enemy("Goomba", 80, 1);
    Koopa = new Enemy("Koopa", 65, 1);
    Coin = new Collectible("Coin");
    Mushroom = new Collectible("Mushroom");
    warpPipe = false;

}

Environment::~Environment() {
    delete Boss;
    delete Goomba;
    delete Koopa;
    delete Coin;
    delete Mushroom;
}

void nextLevel(){
    if(){

    }
}

void Environment::gameOver(){
    
}

void Environment::setWarpPipe(){
    warpPipe = true;
}