#include "Enemy.h"
Enemy::Enemy(std::string type, int percentWin,int numDecrease, Mario* mario){
    player = mario;
    this->type = type;
    this->percentWin = percentWin;
    this->numDecrease = numDecrease;
    //enemy instantiates a mario object
}
Enemy::~Enemy(){
    
}

bool Enemy::fightMario(){
    int randomNumber = rand() % 100;
    //condition to beat mario from random number
    if(randomNumber < percentWin){
        return true;
    }else{
        //lose conditional
        if(player->getPower() >= numDecrease){
            player->decreasePower(player->getPower(), numDecrease);
        }else{
            player->loseLives();
        }
        return false;
    }
}

