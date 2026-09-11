#include "Mario.h"

Mario::Mario(int lives){
    x = 0;
    y = 0;
    V = lives;
    coins = 0;
    powerLevel = 0;
    
}

Mario::Mario(){

}
Mario::~Mario(){

}

int Mario::increasePower(int currentPower){
    for(int i = 0; i < 3; i++){
        if(powerLevels[i] == powerLevel && powerLevel != 2){
            powerLevel = powerLevels[i+1];
        }
    }
}

int Mario::decreasePower(int currentPower, int amount){
    for(int i = 3; i > 0; i--){
        if(powerLevels[i] == powerLevel && powerLevel != 0){
            powerLevel = powerLevels[i-amount];
        }
    }
}
void Mario::setDefeatedEnemies(){
    enemiesDefeated += 1;
}

void Mario::loseLives(){
    V -= 1;
    enemiesDefeated = 0;
}
int Mario::getEnemiesDefeated(){
    return enemiesDefeated;
}
void Mario::setX(){

}
void Mario::setY(){

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



