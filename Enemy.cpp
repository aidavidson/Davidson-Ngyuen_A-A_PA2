
#include "Enemy.h"
Enemy::Enemy(std::string type, int percentWin,int numDecrease){
    mario = new Mario();
    this->type = type;
    this->percentWin = percentWin;
    this->numDecrease = numDecrease;

}
Enemy::~Enemy(){

}
void Enemy::fightMario(){
    srand(time(0));
    int randomNumber = rand() % 100;
    if(randomNumber <= percentWin){

    }else{
        if(mario->getPower() > numDecrease){
            mario->decreasePower(mario->getPower(), numDecrease);
        }
    }
}

