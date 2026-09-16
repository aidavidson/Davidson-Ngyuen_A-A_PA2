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
    powerLevel -= amount;
    if (powerLevel < 0) {
        powerLevel = 0;
    }

}

void Mario::setBeatEnemy(bool tf){
    beatEnemy = tf;
}

void Mario::increaseDefeatedEnemies() {
    if (enemiesDefeated < 6) {
        enemiesDefeated++;
    } else if (enemiesDefeated == 6) {
        gainLives();
        enemiesDefeated++;
    } else {
        enemiesDefeated++;
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
    if (coins < 19) {
        coins += 1;
    } else {
        gainLives();
        coins = 0;
    }

}
int Mario::getCoins(){
    return coins;
}

