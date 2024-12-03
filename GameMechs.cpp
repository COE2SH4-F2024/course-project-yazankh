#include "GameMechs.h"
#include "time.h"
GameMechs::GameMechs()
{
    boardSizeX = 30;
    boardSizeY = 15;
    score = 0;
    exitFlag = false; // Initialize exitFlag
    loseFlag = false; // Initialize loseFlag
    input = '\0';     
}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;
    score = 0;
    exitFlag = false; // Initialize exitFlag
    loseFlag = false; // Initialize loseFlag
    input = '\0';     
}

// do you need a destructor?
GameMechs::~GameMechs()
{

}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() const
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score += 1;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = 1;
}

void GameMechs::setLoseFlag()
{
    loseFlag = 1;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = '\0';
}

// More methods should be added here
const objPos GameMechs::getFoodPos(){

    return foodPos;
}

void GameMechs::generateFood(const objPosArrayList* blockOff){ 
    srand(time(NULL));
    int x,y,i;
    int validPosition = 0;
    while (!validPosition){ //check if food is ontop of any element in the snake before setting those coordinates
         x = rand()%boardSizeX;
         y = rand()%boardSizeY;
        
        for (i = 0; i < blockOff->getSize();i++){

            if(x == blockOff->getElement(i).pos->x && y == blockOff->getElement(i).pos->y){//keep generation coordinates untill they are not on top of the snake
                continue;
            }

            }
        if(x == 0 || y == 0 || x == boardSizeX-1 || y == boardSizeY-1){
                continue;
            }
        validPosition = 1;
    } 
    foodPos.setObjPos(x,y,'*');
}