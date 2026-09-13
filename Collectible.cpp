#include "Collectible.h"

Collectible::Collectible(std::string type){
    mario = new Mario();
    this->type = type;
}
Collectible::~Collectible(){
    delete mario;
}
void Collectible::collectCoin(){
    mario->collectCoin();
}
void Collectible::collectMushroom(){
    mario->increasePower(mario->getPower());
}