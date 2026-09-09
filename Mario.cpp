#include "Mario.h"

Mario::Mario(int lives){
    x = 0;
    y = 0;
    V = lives;
    coins = 0;
    powerLevel = 0;
    
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

int Mario::decreasePower(int currentPower){
    for(int i = 3; i > 0; i--){
        if(powerLevels[i] == powerLevel && powerLevel != 0){
            powerLevel = powerLevels[i-1];
        }
    }
}



