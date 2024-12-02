#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
using namespace std;

#define DELAY_CONST 100000



void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



Player* Playerptr;
GameMechs* game;
int main(void)
{

    Initialize();

    while(game->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    game = new GameMechs(30,15);
    Playerptr = new Player(game);
    game->generateFood(Playerptr->getPlayerPos());
    
    
}

void GetInput(void)
{
    if (MacUILib_hasChar() == 1){
   game->setInput(MacUILib_getChar());
    }
}

void RunLogic(void)
{
    
    Playerptr->updatePlayerDir();
    
    Playerptr->movePlayer();
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    // Draw the game board
    for (int y = 0; y <= game->getBoardSizeY(); y++) {
        for (int x = 0; x <= game->getBoardSizeX(); x++) {
            if (y == 0 || y == game->getBoardSizeY() || x == 0 || x == game->getBoardSizeX()) {
                cout << '#';
            } else {
                // Check if this position matches a part of the snake body
                bool isSnakeBody = false;
                const objPosArrayList* snakeBody = Playerptr->getPlayerPos();
                for (int i = 0; i < snakeBody->getSize(); i++) {
                    if (snakeBody->getElement(i).pos->x == x && snakeBody->getElement(i).pos->y == y) {
                        cout << snakeBody->getElement(i).symbol;
                        isSnakeBody = true;
                        break;
                    }
                }

                // Draw the food if not part of the snake body
                if (!isSnakeBody) {
                    if (y == game->getFoodPos().pos->y && x == game->getFoodPos().pos->x) {
                        cout << game->getFoodPos().symbol;
                    } else {
                        cout << ' ';
                    }
                }
            }
        }
        cout << endl;
    }

    // Display the score
    cout << "Score: " << game->getScore();
    
    // Check lose condition
    if (game->getLoseFlagStatus()) {
        game->setExitTrue();
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    if (game->getLoseFlagStatus()==1)
    {
        cout<<endl<<"You Lost!"<<endl;
        
    }
    delete game;
    game = nullptr;
    delete Playerptr;
    Playerptr = nullptr;
    MacUILib_uninit();
    
}
