#include "objPos.h"

objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Respect the rule of six / minimum four
// [TODO] Implement the missing special member functions to meet the minimum four rule
objPos::objPos(const objPos& other){ //copy constructor
        pos = new Pos;
        pos->x = other.pos->x;
        pos->y = other.pos->y;
        symbol = other.symbol;

}

objPos& objPos::operator=(const objPos& other){ //copy assignment operator
    if (this!=&other){ //need the & because in C having & in the parameter just means pass by reference not a pointer, need to still reference again in code
        delete pos;
        pos = new Pos;
        pos->x = other.pos->x;//references behave like the objects not the pointers. (dot operator)
        pos->y = other.pos->y;
        symbol = other.symbol;
    }
    return *this;

}

objPos::~objPos(){//destructor
    delete pos;
}

void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

char objPos::getSymbol() const
{
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}
