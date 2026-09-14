#include "Game.h"



Game::Game(fileProcessor* fp){
    instancefp = fp;
    // starts with -1 for level so when it increments to level 0 
    //in world it doesn't skip a level
    int currentLevel = -1;
    //creates a world object which populates with all the level data
    World(fp->accessVal(levelInd), fp->accessVal(dimenInd), 
          fp->accessVal(perCoinInd),fp->accessVal(perMushInd),
          fp->accessVal(perGoomInd), fp->accessVal(perKoopInd),
          fp->accessVal(perNothInd), currentLevel);
    //creates a mario object to use for the whole game
    mario = new Mario(fp->accessVal(numLiveInd));
    //checks to see if file operations works properly
    error = 0;
    marioImpacts = Environment(mario, fp->accessVal(dimenInd));
    
}


int Game::initializeGame(){
    //checks if instancefp works properly
    error = instancefp->processFile();
    //if not it returns and cuts out before anthing happens
    if(error == 1){
        std::cout << "the input values for the input file are wrong" << std::endl;
        return 1;
    }
    //finds random indexes for mario in a new level --> should be in a class idk where for now
    int randomX = rand() % instancefp->accessVal(dimenInd);
    int randomY = rand() % instancefp->accessVal(dimenInd);
    //sets the current level from -1 -> 0
    world.setLevel();
    //sets marios position in the level
    mario->setX(randomX);
    mario->setY(randomY); 

}

void Game::repeatedAction(){
    while(mario->getLives() != 0 || marioImpacts.isGameWon() == false){
        if(world.isCurrentLevelComplete() == true){
            world.setLevelGridElement('x', mario->getX(), mario->getY());
            marioImpacts.marioMove();
            char** currentLevelGrid = world.getLevelgrid(world.getLevel());
            switch(currentLevelGrid[mario->getX()][mario->getY()]){
                case 'x':
                    //nothing
                    world.setLevelGridElement('H', mario->getX(), mario->getY());
                    break;
                case 'm':
                    marioImpacts.accessCollectible(marioImpacts.accessCollectible("Mushroom")->getName());
                    world.setLevelGridElement('H', mario->getX(), mario->getY());
                    break;
                case 'c':
                    marioImpacts.accessCollectible(marioImpacts.accessCollectible("Coin")->getName());
                    world.setLevelGridElement('H', mario->getX(), mario->getY());
                    break;
                case 'g':
                    marioImpacts.fightMario(marioImpacts.accessEnemy("Goomba"));
                    world.setLevelGridElement('H', mario->getX(), mario->getY());
                    break;
                case 'k':
                    marioImpacts.fightMario(marioImpacts.accessEnemy("Koopa"));
                    world.setLevelGridElement('H', mario->getX(), mario->getY());
                    break;
                case 'b':
                    marioImpacts.fightMario(marioImpacts.accessEnemy("Boss"));
                    world.setLevelGridElement('H', mario->getX(), mario->getY());
                    break;
                case 'w':
                    world.setLevelGridElement('H', mario->getX(), mario->getY());
                    world.setLevel();
                    break;
                default:
                    break;
            }
        }
    }
}
