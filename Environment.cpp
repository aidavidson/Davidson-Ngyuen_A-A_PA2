#include "Environment.h" 
#include "Level.h"

Environment::Environment(){
    
}

Environment::Environment(Mario* mario, int L) {
    //these are the different objects mario can collide with and their properties show 
    //the possiblity of winning and how much power level they take away
    worldLength = L;
    player = mario;
    Boss = new Enemy("Boss", 50, 2, player);
    Goomba = new Enemy("Goomba", 80, 1, player);
    Koopa = new Enemy("Koopa", 65, 1, player);
    Coin = new Collectible("Coin", player);
    Mushroom = new Collectible("Mushroom", player);
    gameComplete = false;
}

Environment::~Environment() {
    delete Boss;
    delete Goomba;
    delete Koopa;
    delete Coin;
    delete Mushroom;
}

void Environment::nextLevel(){
    if(currentLevel != nullptr && currentLevel->isComplete()) {
        //move on to next level
    }
}

void Environment::gameOver(){
    
}
std::string Environment::marioMove(fileProcessor* fp){
    srand(time(0));
    int randomVal = rand() % 4;
    switch(randomVal){
        case 0:
            if(player->getX() == 0){
                player->setX(worldLength-1);
            }
            else{
                player->setX(player->getX()-1);
            }
            return "Mario will move LEFT";
            break;
        case 1:
            if(player->getX() == (worldLength-1)){
                player->setX(0);
            }else{
                player->setX(player->getX()+1);
            }
            return "Mario will move RIGHT";
            break;
        case 2:
            if(player->getY() == 0){
                player->setY(worldLength-1);
            }
            else{
                player->setY(player->getY()-1);
            }
            return "Mario will move UP";
            break;
        case 3:
            if(player->getY() == (worldLength-1)){
                player->setY(0);
                
            }else{
                player->setY(player->getY()+1);
            }
            return "Mario will move DOWN";
            break;
    }
}

bool Environment::isGameWon(){
    return gameComplete;
}

bool Environment::fightMario(Enemy* enemy){
    return enemy->fightMario();
}
void Environment::marioCollect(Collectible* collectible, std::string which){
    if(which == "Coin"){
        collectible->collectCoin();
    }else if(which == "Mushroom"){
        collectible->collectMushroom();
    }
}

Collectible* Environment::accessCollectible(std::string typeCollectible){
    if(typeCollectible == "Coin"){
        return Coin;
    }else if(typeCollectible == "Mushroom"){
        return Mushroom;
    }
}
Enemy* Environment::accessEnemy(std::string typeEnemy){
    if(typeEnemy =="Boss"){
        return Boss;
    }else if(typeEnemy == "Goomba"){
        return Goomba;
    }else if(typeEnemy == "Koopa"){
        return Koopa;
    }
}
