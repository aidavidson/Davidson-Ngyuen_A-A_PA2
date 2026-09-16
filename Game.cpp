#include "Game.h"

Game::Game(fileProcessor* fp){
    instancefp = fp;
    // starts with -1 for level so when it increments to level 0 
    //in world it doesn't skip a level

    error = instancefp->processFile();
    //if not it returns and cuts out before anthing happens
    //try-catch statements to open files
    error = instancefp->processFile();
    if (error != 0) {
        throw std::runtime_error("Input file error");
    }

    int currentLevel = -1;
    //creates a world object which populates with all the level data
    world = new World(fp->accessVal(levelInd), fp->accessVal(dimenInd), 
          fp->accessVal(perCoinInd),fp->accessVal(perMushInd),
          fp->accessVal(perGoomInd), fp->accessVal(perKoopInd),
          fp->accessVal(perNothInd), currentLevel);
    //creates a mario object to use for the whole game
    mario = new Mario(fp->accessVal(numLiveInd));
    //checks to see if file operations works properly
    error = 0;
    marioImpacts =new Environment(mario, fp->accessVal(dimenInd));
    initializeGame();
    wonBattle = false;
}

Game::~Game(){
    delete mario;
    delete world;
    delete marioImpacts;
}

int Game::initializeGame(){
    //checks if instancefp works properly
    //finds random indexes for mario in a new level --> should be in a class idk where for now
    int randomX = rand() % instancefp->accessVal(dimenInd);
    int randomY = rand() % instancefp->accessVal(dimenInd);
    //sets the current level from -1 -> 0
    world->setLevel();
    //sets marios position in the level
    mario->setX(randomX);
    mario->setY(randomY); 
    return 0;
}

std::string Game::marioPosText(){
    std::string txt;
    txt += "Mario is starting in position: (";
    txt += std::to_string(mario->getX());
    txt += "," ;
    txt += std::to_string(mario->getY());
    txt += ")";
    return txt;
}

std::string Game::gameText(){
    std::string txt;
    txt += "Level: " ;
    txt += std::to_string(world->getLevel());
    txt += ".";
    txt += " Mario is at position: (";
    txt += std::to_string(mario->getX());
    txt += ",";
    txt += std::to_string(mario->getY());
    txt += "). Mario is at power level ";
    txt += std::to_string(mario->getPower());
    txt += ".";
    return txt;
}

std::string Game::finishGameTxt(){
    std::string txt;
    txt += "Mario has ";
    txt += std::to_string(mario->getLives());
    txt += " lives left. Mario has ";
    txt += std::to_string(mario->getCoins());
    txt += " coins.";
    return txt;
}
//local function declarations for repeated action


void Game::repeatedAction(){
    std::string direction;
    int increments = 0;
    
    
    while(mario->getLives() != 0 && marioImpacts->isGameWon() == false){ 

        instancefp->addToOutput(world->levelPrint(world->getLevel())); //add to the fileprocessor pointer
        if(increments == 0){
            instancefp->addToOutput(marioPosText());
            world->setLevelGridElement('H', mario->getX(), mario->getY());
            instancefp->addToOutput(world->levelPrint(world->getLevel()));
        }
        //if (world->isCurrentLevelComplete() == 0) { //if the current level in the world isn't complete
        // sets marios first position as an H
        
        //ensures game initializatio is only called once
        char** currentLevelGrid = world->getLevelgrid(world->getLevel());
        switch(currentLevelGrid[mario->getX()][mario->getY()]){
            case 'x':
                nothingAction();
                break;
            case 'm':
                mushroomAction();
                break;
            case 'c':
                coinAction();
                break;
            case 'g':
                goombaAction();
                break;
            case 'k':
                koopaAction();
                break;
            case 'b':
                bossAction();
                break;
            case 'w':
                warpAction();
                break;
            default:
                break;

        }
            
        //sets marios past position to an x 
        world->setLevelGridElement('x', mario->getX(), mario->getY());
        direction = marioImpacts->marioMove(instancefp);
        
        world->setLevelGridElement('H', mario->getX(), mario->getY());
        instancefp->addToOutput(gameText());
        
        break;
    increments++;
    }
    instancefp->addToOutput(finishGameTxt());
    instancefp->addToOutput(direction);
}

void Game::nothingAction(){
    world->setLevelGridElement('H', mario->getX(), mario->getY());
    instancefp->addToOutput("Mario visited an empty space. ");
    
}
void Game::mushroomAction(){
    marioImpacts->marioCollect(marioImpacts->accessCollectible("Mushroom"), marioImpacts->accessCollectible("Mushroom")->getName());
    world->setLevelGridElement('H', mario->getX(), mario->getY());
    if(mario->getPower() < 2){
        instancefp->addToOutput("Mario collected a mushroom.");
    }
}
void Game::coinAction(){
    marioImpacts->marioCollect(marioImpacts->accessCollectible("Coin"), marioImpacts->accessCollectible("Coin")->getName());
    world->setLevelGridElement('H', mario->getX(), mario->getY());
    instancefp->addToOutput("Mario collected a coin. ");
}
void Game::goombaAction(){
    marioImpacts->marioCollect(marioImpacts->accessCollectible("Coin"), marioImpacts->accessCollectible("Coin")->getName());
    world->setLevelGridElement('H', mario->getX(), mario->getY());
    instancefp->addToOutput("Mario collected a coin. ");
}
void Game::koopaAction(){
    wonBattle = marioImpacts->fightMario(marioImpacts->accessEnemy("Goomba"));
    world->setLevelGridElement('H', mario->getX(), mario->getY());
    instancefp->addToOutput("Mario encountered a goomba "); 
    if(wonBattle == true){
        instancefp->addToOutput("and won.");
        mario->increaseDefeatedEnemies();
    }else{
        instancefp->addToOutput("and loss.");
    }                   
}

void Game::bossAction(){
    wonBattle = marioImpacts->fightMario(marioImpacts->accessEnemy("Boss"));
    world->setLevelGridElement('H', mario->getX(), mario->getY());
    instancefp->addToOutput("Mario encountered a boss ");
    if(wonBattle == true){
        instancefp->addToOutput("and won.");
        mario->increaseDefeatedEnemies();
        world->setLevel();
    }else{
        instancefp->addToOutput("and loss.");
    }
}

void Game::warpAction(){
    world->setLevelGridElement('H', mario->getX(), mario->getY());
    world->setLevel();
    instancefp->addToOutput("Mario encountered a warp pipe. ");

}




/*


        
        direction = marioImpacts->marioMove(instancefp);
        
        switch(currentLevelGrid[mario->getX()][mario->getY()]){
            case 'x':
                //nothing
                world->setLevelGridElement('H', mario->getX(), mario->getY());
                instancefp->addToOutput("Mario visited an empty space. ");
                break;
            case 'm':
                marioImpacts->marioCollect(marioImpacts->accessCollectible("Mushroom"), marioImpacts->accessCollectible("Mushroom")->getName());
                world->setLevelGridElement('H', mario->getX(), mario->getY());
                if(mario->getPower() < 2){
                    instancefp->addToOutput("Mario collected a mushroom. ");
                }
                break;
            case 'c':
                marioImpacts->marioCollect(marioImpacts->accessCollectible("Coin"), marioImpacts->accessCollectible("Coin")->getName());
                world->setLevelGridElement('H', mario->getX(), mario->getY());
                instancefp->addToOutput("Mario collected a coin. ");
                break;
            case 'g':
                wonBattle = marioImpacts->fightMario(marioImpacts->accessEnemy("Goomba"));
                world->setLevelGridElement('H', mario->getX(), mario->getY());
                instancefp->addToOutput("Mario encountered a goomba "); 
                if(wonBattle == true){
                    instancefp->addToOutput("and won.");
                    mario->increaseDefeatedEnemies();
                }else{
                    instancefp->addToOutput("and loss.");
                }                   
                break;
            case 'k':
                wonBattle = marioImpacts->fightMario(marioImpacts->accessEnemy("Koopa"));
                world->setLevelGridElement('H', mario->getX(), mario->getY());
                instancefp->addToOutput("Mario encountered a koopa ");
                if(wonBattle == true){
                    instancefp->addToOutput("and won.");
                    mario->increaseDefeatedEnemies();
                }else{
                    instancefp->addToOutput("and loss.");
                }
                break;
            case 'b':
                wonBattle = marioImpacts->fightMario(marioImpacts->accessEnemy("Boss"));
                world->setLevelGridElement('H', mario->getX(), mario->getY());
                instancefp->addToOutput("Mario encountered a boss ");
                if(wonBattle == true){
                    instancefp->addToOutput("and won.");
                    mario->increaseDefeatedEnemies();
                    world->setLevel();
                }else{
                    instancefp->addToOutput("and loss.");
                }
                

                break;
            case 'w':
                world->setLevelGridElement('H', mario->getX(), mario->getY());
                world->setLevel();
                instancefp->addToOutput("Mario encountered a warp pipe. ");
                break;
            default:
                break;
        }
        // size_t length = sizeof(currentLevelGrid) / sizeof(currentLevelGrid[0]);

        // for(int i = 0; i < length; i++){
        //     delete[] currentLevelGrid[i];
        // }
        //delete [] currentLevelGrid;
    //}
        increments++;
    }
    
*/