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
    wonBattle = false;
    
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
std::string Game::marioPosText(){
    std::string txt;
    txt += "\nMario is starting in position: (";
    txt += mario->getX();
    txt += "," ;
    txt += mario->getX();
    txt += ")";
    return txt;
}
std::string Game::gameText(){
    std::string txt;
    txt += "Level: " ;
    txt += world.getLevel();
    txt += ".";
    txt += " Mario is at position: (";
    txt += mario->getX();
    txt += ",";
    txt += "). Mario is at power level";
    txt += mario->getPower();
    txt += "."
}
std::string Game::finishGameTxt(){
    std::string txt;
    txt += "Mario has ";
    txt += mario->getLives();
    txt += " lives left. Mario has ";
    txt += mario->getCoins();
    txt += " coins.";
}
void Game::repeatedAction(){
    std::string direction;
    int increments;
    while(mario->getLives() != 0 || marioImpacts.isGameWon() == false){
        if(world.isCurrentLevelComplete() == true){
            instancefp->addToOutput(world.levelPrint(world.getLevel()));
            
            world.setLevelGridElement('x', mario->getX(), mario->getY());
            if(increments == 0){
                instancefp->addToOutput(marioPosText());
                instancefp->addToOutput(world.levelPrint(world.getLevel()));
                
            }
            instancefp->addToOutput(gameText());
            direction = marioImpacts.marioMove(instancefp);
            char** currentLevelGrid = world.getLevelgrid(world.getLevel());
            switch(currentLevelGrid[mario->getX()][mario->getY()]){
                case 'x':
                    //nothing
                    world.setLevelGridElement('H', mario->getX(), mario->getY());
                    instancefp->addToOutput("Mario visited an empty space. ");
                    break;
                case 'm':
                    marioImpacts.accessCollectible(marioImpacts.accessCollectible("Mushroom")->getName());
                    world.setLevelGridElement('H', mario->getX(), mario->getY());
                    if(mario->getPower() < 2){
                        instancefp->addToOutput("Mario collected a mushroom. ");
                    }
                    break;
                case 'c':
                    marioImpacts.accessCollectible(marioImpacts.accessCollectible("Coin")->getName());
                    world.setLevelGridElement('H', mario->getX(), mario->getY());
                    instancefp->addToOutput("Mario collected a coin. ");
                    break;
                case 'g':
                    wonBattle = marioImpacts.fightMario(marioImpacts.accessEnemy("Goomba"));
                    world.setLevelGridElement('H', mario->getX(), mario->getY());
                    instancefp->addToOutput("Mario encountered a goomba "); 
                    if(wonBattle == true){
                        instancefp->addToOutput("and won.");
                    }else{
                        instancefp->addToOutput("and loss.");
                    }                   
                    break;
                case 'k':
                    wonBattle = marioImpacts.fightMario(marioImpacts.accessEnemy("Koopa"));
                    world.setLevelGridElement('H', mario->getX(), mario->getY());
                    instancefp->addToOutput("Mario encountered a koopa ");
                    if(wonBattle == true){
                        instancefp->addToOutput("and won.");
                    }else{
                        instancefp->addToOutput("and loss.");
                    }
                    break;
                case 'b':
                    wonBattle = marioImpacts.fightMario(marioImpacts.accessEnemy("Boss"));
                    world.setLevelGridElement('H', mario->getX(), mario->getY());
                    instancefp->addToOutput("Mario encountered a boss ");
                    if(wonBattle == true){
                        instancefp->addToOutput("and won.");
                    }else{
                        instancefp->addToOutput("and loss.");
                    }
                    

                    break;
                case 'w':
                    world.setLevelGridElement('H', mario->getX(), mario->getY());
                    world.setLevel();
                    instancefp->addToOutput("Mario encountered a warp pipe. ");
                    break;
                default:
                    break;
            }
        }
    }
    instancefp->addToOutput(finishGameTxt());
    instancefp->addToOutput(direction);
}
