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
bool Enemy::fightMario(){
    srand(time(0));
    int randomNumber = rand() % 100;
    if(randomNumber <= percentWin){
        return true;
    }else{
        if(player->getPower() > numDecrease){
            player->decreasePower(player->getPower(), numDecrease);
        }else{
            player->loseLives();
        }
        return false;
    }
}

