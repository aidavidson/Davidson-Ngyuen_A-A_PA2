#include "Mario.h"

Mario::Mario(int lives){
    x = 0;
    y = 0;
    V = lives;
    coins = 0;
    powerLevel = 0;
    beatEnemy = false;
    enemiesDefeated = 0;
}

Mario::~Mario(){

}

void Mario::increasePower(int currentPower){
    if (powerLevel < 2) {
        powerLevel++;
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
    if (enemiesDefeated == 7) {
        gainLives();
        enemiesDefeated = 0;
    } else {
        enemiesDefeated += 1;
    }
}

void Mario::loseLives(){
    V -= 1;
    enemiesDefeated = 0;
    powerLevel = 0;
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
    if (coins <= 20) {
        coins += 1;
    } else {
        gainLives();
        coins = 0;
    }

}
int Mario::getCoins(){
    return coins;
}

