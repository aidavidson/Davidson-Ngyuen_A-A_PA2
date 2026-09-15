#include "Mario.h"

Mario::Mario(int lives){
    x = 0;
    y = 0;
    V = lives;
    coins = 0;
    powerLevel = 0;
    beatEnemy = false;
}


Mario::~Mario(){

}

void Mario::increasePower(int currentPower){
    for(int i = 0; i < 3; i++){
        if(powerLevels[i] == powerLevel && powerLevel != 2){
            powerLevel = powerLevels[i+1];
        }
    }
}

void Mario::decreasePower(int currentPower, int amount){
    //why do we need a for loop here?
    // for(int i = 2; i >= 0; i--){
    //     if(powerLevels[i] == powerLevel && powerLevel != 0){
    //         powerLevel = powerLevels[i-amount];
    //     }
    // }

    powerLevel -= amount;
    if (powerLevel < 0) {
        powerLevel = 0;
    }

}
void Mario::setBeatEnemy(bool tf){
    beatEnemy = tf;
}
void Mario::increaseDefeatedEnemies(){
    enemiesDefeated += 1;
}

void Mario::loseLives(){
    V -= 1;
    enemiesDefeated = 0;
}
int Mario::getEnemiesDefeated(){
    return enemiesDefeated;
}
//value is parameter in method
void Mario::setX(int val){
    x = val; 
}
void Mario::setY(int val){
    y = val;
}
int Mario::getX(){
    return x;
}

int Mario::getY(){
    return y;
}

int Mario::getLives(){
    return V;
}
int Mario::getPower(){
    return powerLevel;
}
void Mario::gainLives(){
    V += 1;
}

void Mario::collectCoin(){
    coins += 1;
}
int Mario::getCoins(){
    return coins;
}

