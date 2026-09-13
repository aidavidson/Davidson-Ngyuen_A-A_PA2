#include "Enemy.h"
Enemy::Enemy(std::string type, int percentWin,int numDecrease, Mario* mario){
    player = mario;
    this->type = type;
    this->percentWin = percentWin;
    this->numDecrease = numDecrease;
    //enemy instantiates a mario object
}
Enemy::~Enemy(){
    delete player;
}
void Enemy::fightMario(){
    srand(time(0));
    int randomNumber = rand() % 100;
    if(randomNumber <= percentWin){

    }else{
        if(player->getPower() > numDecrease){
            player->decreasePower(player->getPower(), numDecrease);
        }
    }
}

