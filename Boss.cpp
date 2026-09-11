#include "Boss.h"

Boss::Boss(){

}
Boss::~Boss(){

} 
void Boss::fightBoss(){
    srand(time(0));
    int randomNum;
    randomNum = rand() % (2-1 + 1) + 1;
    if(randomNum = 2){
        //win
        
    }else{
        //lose
        if(character.getPower() == 2){
            character.decreasePower(character.getPower(), 2);
        }
    }
}