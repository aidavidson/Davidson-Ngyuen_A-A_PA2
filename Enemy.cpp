#include "Enemy.h"

Enemy::Enemy(std::string eType){
    type = eType;
    dead = false;

}
Enemy::~Enemy(){

}
int Enemy::checkEnemiesDefeated(){
    if(mario.getEnemiesDefeated() >= 7){
        mario.gainLives();
    }
    return mario.getEnemiesDefeated();
}

void Enemy::battleEnemy(){
    srand(time(0));
    if(type == "Goomba"){
        int randNum;
        randNum = rand() % (5-1 + 1) + 1;
        if(randNum > 1){
            mario.setDefeatedEnemies();
        }else{
            if(mario.getPower() != 0){
                mario.decreasePower(mario.getPower(), 1);
            }else{
                if(mario.getLives() != 0){
                    //end game
                    dead = true;
                    return;
                }else{
                    mario.loseLives();
                }
            }
        }
    }else{
        int randNum;
        randNum = rand() % (20-13 + 1) + 13;
        if(randNum > 7){
            mario.setDefeatedEnemies();
        }else{
            if(mario.getPower() != 0){
                mario.decreasePower(mario.getPower(), 1);
            }else{
                if(mario.getLives() != 0){
                    //end game
                    dead = true;
                    return;
                }else{
                    mario.loseLives();
                }
            }
        }
    }
}