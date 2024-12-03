#include "Player.h"
#include <iostream>
 
Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(objPos (15,7,'O'));
     
    // more actions to be included
}


Player::~Player()
{
    delete playerPosList;// delete any heap members here
    playerPosList = nullptr;
}

const objPosArrayList* Player::getPlayerPos() 
{
    return playerPosList; // Return reference to the entire array list
}


void Player::updatePlayerDir()
{
        // PPA3 input processing logic    
    if(this->mainGameMechsRef->getInput() != 0)  // if not null character
    {
        switch(this->mainGameMechsRef->getInput())
        {    
            case 'E' :               
            case 'e' :  // exit
                this->mainGameMechsRef->setExitTrue();
                break;

            // Add more key processing here
            case 'W':
            case 'w':
                if (this->myDir != DOWN){
                    this->myDir = UP;
                    break;
                }
                else{
                    break;
                }
            // Add more key processing here
            case 'S':
            case 's':
                if (this->myDir != UP){
                        
                        this->myDir = DOWN;
                        break;
                    }
                    else{
                        break;
                    }
                 
            // Add more key processing here
            case 'A':
            case 'a':
                if (this->myDir != RIGHT){
                            
                            this->myDir = LEFT;
                            break;
                        }
                        else{
                            break;
                        }
            case 'D':
            case 'd':
                if (this->myDir != LEFT){
                        
                        this->myDir = RIGHT;
                        break;
                    }
                    else{
                        break;
                    }
            case 'X':
            case 'x':
                mainGameMechsRef->incrementScore();
                break;
            case 'L':
            case 'l':
                mainGameMechsRef->setLoseFlag();
                break;
            case 'J':
            case 'j':
                mainGameMechsRef->generateFood(playerPosList);
                break;
            default:
                
                break;

        }
         
        this->mainGameMechsRef->setInput('\0');
        
    }
       
}

void Player::movePlayer()
{
    objPos headElement = this->playerPosList->getHeadElement(); 
     for(int i = 1; i < playerPosList->getSize();i++){
        if (headElement.pos->x == playerPosList->getElement(i).pos->x && headElement.pos->y == playerPosList->getElement(i).pos->y)
        {
            mainGameMechsRef->setLoseFlag();
        }
     }
        switch(this->myDir)
    {
        case UP:
            headElement.pos->y -= 1;
             
            break;
        case DOWN:
            headElement.pos->y += 1;
             
            break;
        case LEFT:
            headElement.pos->x -= 1;
             
        
            break;
        case RIGHT:
            headElement.pos->x += 1;
             
            
            break;
        case STOP:
            
            // No movement
            break;
    }
    // [TODO] : Heed the border wraparound!!!
    if (headElement.pos->x>=this->mainGameMechsRef->getBoardSizeX()){
        headElement.pos->x = 1;
    }
    else if (headElement.pos->x<1){
        headElement.pos->x = mainGameMechsRef->getBoardSizeX()-1;
    }
    if (headElement.pos->y>=this->mainGameMechsRef->getBoardSizeY()){
        headElement.pos->y = 1;
    }
    else if (headElement.pos->y<1){
        headElement.pos->y = mainGameMechsRef->getBoardSizeY()-1;
    }
    if (headElement.pos->x == mainGameMechsRef->getFoodPos().pos->x && headElement.pos->y == mainGameMechsRef->getFoodPos().pos->y){ //Check if snake ate food
        playerPosList->insertHead(objPos(headElement.pos->x, headElement.pos->y, 'O')); //if it did then keep the tail
        mainGameMechsRef->generateFood(playerPosList);
        mainGameMechsRef->incrementScore();
    }
    else{
    playerPosList->insertHead(objPos(headElement.pos->x, headElement.pos->y, 'O')); //if it didnt eat food then remove tail
    playerPosList->removeTail();
}
    }
// PPA3 Finite State Machine logic


// More methods to be added
