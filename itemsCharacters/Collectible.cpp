#include "Collectible.h"

Collectible::Collectible(std::string type, Mario* mario){
    player = mario;
    this->type = type;
}
Collectible::~Collectible(){
    delete player;
}
void Collectible::collectCoin(){
    // just collects coin in mario class
    player->collectCoin();
}

void Collectible::collectMushroom(){
    //increases power based on marios current power
    player->increasePower(player->getPower());
}

std::string Collectible::getName(){
    return type;
}