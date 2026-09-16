#include "Game.h"

Game::Game(fileProcessor* fp){
    instancefp = fp;
    // starts with -1 for level so when it increments to level 0 
    //in world it doesn't skip a level

    error = instancefp->processFile();
    //if not it returns and cuts out before anthing happens
    //try-catch statements to open files
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
    txt += std::to_string(mario->getY());
    txt += "," ;
    txt += std::to_string(mario->getX());
    txt += ")";
    return txt;
}

std::string Game::gameText(){
    std::string txt;
    txt += "Level: " ;
    txt += std::to_string(world->getLevel());
    txt += ".";
    txt += " Mario is at position: (";
    txt += std::to_string(mario->getY());
    txt += ",";
    txt += std::to_string(mario->getX());
    txt += "). Mario is at power level ";
    txt += std::to_string(mario->getPower());
    txt += ". ";
    return txt;
}

std::string Game::finishGameTxt(){
    std::string txt;
    txt += "Mario has ";
    txt += std::to_string(mario->getLives());
    txt += " lives left. Mario has ";
    txt += std::to_string(mario->getCoins());
    txt += " coins. ";
    return txt;
}
//local function declarations for repeated action


//
void Game::repeatedAction(){
    std::string direction;
    int increments = 0;

    // Print every initial level before displaying Mario.
    for (int i = 0; i < instancefp->accessVal(levelInd); i++) {
        instancefp->addToOutput(world->levelPrint(i) + "\n");
    }

    while(mario->getLives() != 0 && !marioImpacts->isGameWon()){         
        //ensures game initialization is only called once
        int yPos = mario->getY();
        int xPos = mario->getX();
        char** currentLevelGrid = world->getLevelgrid(world->getLevel());
        int livesBefore = mario->getLives();
        int levelBefore = world->getLevel();
        char tile = currentLevelGrid[yPos][xPos];

        instancefp->addToOutput(gameText());

        switch(tile){
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
            
        // Capture the encounter's level before movement, even after a transition.
        char** encounterGrid = world->getLevelgrid(levelBefore);
        char underneath = encounterGrid[yPos][xPos];
        encounterGrid[yPos][xPos] = 'H';
        std::string snapshot = world->levelPrint(levelBefore);
        encounterGrid[yPos][xPos] = underneath;

    direction = "STAY PUT";

    if (mario->getLives() > 0 && !marioImpacts->isGameWon()) {
        if (world->getLevel() != levelBefore) {
            // Boss victory or warp moved Mario to another level.
            int n = instancefp->accessVal(dimenInd);
            mario->setX(rand() % n);
            mario->setY(rand() % n);
        } else {
            bool lostLife = mario->getLives() < livesBefore;
            bool lostToBoss = tile == 'b' && !wonBattle;

            if (!lostLife && !lostToBoss) {
                direction = marioImpacts->marioMove(instancefp);
            }
        }
    }

    increments++;

        // Log each interaction.
        instancefp->addToOutput(finishGameTxt());
        instancefp->addToOutput(" " + direction + "\n");
        instancefp->addToOutput(snapshot + "\n");
    } // End of while loop.

    // Log the final result.
    if (marioImpacts->isGameWon()) {
        instancefp->addToOutput("Mario won. ");
    } else {
        instancefp->addToOutput("Mario lost. ");
    }

    instancefp->addToOutput("Total moves: " + std::to_string(increments) + "\n");
}

void Game::nothingAction(){
    instancefp->addToOutput("Mario visited an empty space. ");
}

void Game::mushroomAction(){
    marioImpacts->marioCollect(marioImpacts->accessCollectible("Mushroom"), marioImpacts->accessCollectible("Mushroom")->getName());
    instancefp->addToOutput("Mario collected a mushroom.");
    world->setLevelGridElement('x', mario->getY(), mario->getX());
}

void Game::coinAction(){
    marioImpacts->marioCollect(marioImpacts->accessCollectible("Coin"), marioImpacts->accessCollectible("Coin")->getName());
    instancefp->addToOutput("Mario collected a coin. ");
    world->setLevelGridElement('x', mario->getY(), mario->getX());
}

void Game::goombaAction() {
    wonBattle = marioImpacts->fightMario(
        marioImpacts->accessEnemy("Goomba")
    );
    instancefp->addToOutput("Mario encountered a goomba ");
    if (wonBattle) {
        instancefp->addToOutput("and won. ");
        mario->increaseDefeatedEnemies();

        world->setLevelGridElement(
            'x', mario->getY(), mario->getX()
        );
    } else {
        instancefp->addToOutput("and lost. ");
    }
}

void Game::koopaAction(){
    wonBattle = marioImpacts->fightMario(marioImpacts->accessEnemy("Koopa"));
    instancefp->addToOutput("Mario encountered a koopa "); 
    if(wonBattle == true){
        instancefp->addToOutput("and won.");
        mario->increaseDefeatedEnemies();
        world->setLevelGridElement('x', mario->getY(), mario->getX());
    }else{
        instancefp->addToOutput("and loss.");
    }                   
}

void Game::bossAction(){
    wonBattle = marioImpacts->fightMario(marioImpacts->accessEnemy("Boss"));
    instancefp->addToOutput("Mario encountered a boss ");
    if (wonBattle) {
        instancefp->addToOutput("and won.");
        mario->increaseDefeatedEnemies();

        // Clear the boss in the current level before advancing.
        world->setLevelGridElement('x', mario->getY(), mario->getX());

        //final boss
        if (world->getLevel() == -1) {
            marioImpacts->markGameWon();
        }
    } else {
        instancefp->addToOutput("and lost.");
    }
}

void Game::warpAction(){
    world->setLevel();
    instancefp->addToOutput("Mario encountered a warp pipe. ");

}
