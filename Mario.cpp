#include "Mario.h"

Mario::Mario(int lives){
    V = lives;
    coins = 0;
    powerLevel = "PL0";
    powerLevels = new std::string[3];
    powerLevels[0] = "PL0";
    powerLevels[1] = "PL1";
    powerLevels[2] = "PL2";
}
Mario::~Mario(){

}

std::string Mario::increasePower(std::string currentPower){
    for(int i = 0; i < sizeof(powerLevels)/sizeof(powerLevels[0]); i++){
        if(powerLevels[i] == powerLevel && powerLevel != "PL2"){
            powerLevel = powerLevels[i+1];
        }
    }
}

std::string Mario::decreasePower(std::string currentPower){
    for(int i = sizeof(powerLevels)/sizeof(powerLevels[0]; i > 0; i--); i++){
        if(powerLevels[i] == powerLevel && powerLevel != "PL0"){
            powerLevel = powerLevels[i-1];
        }
    }
}
std::string Mario::modPower(std::string object){
    if(object == "M"){
        increasePower(powerLevel);
    }else if(object == "E"){
        decreasePower(powerLevel);
    }
}


