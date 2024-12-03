#include "objPosArrayList.h"

// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.
#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()//initialize default values and allocate objPos's in list
{
    arrayCapacity = 200;
    listSize = 0;
    aList = new objPos[arrayCapacity];
}

objPosArrayList::~objPosArrayList()//delete everything in the list when destructor invoked.
{
    if (aList != nullptr){
        delete[] aList;
        aList = nullptr;
    }
}

int objPosArrayList::getSize() const //most of these are self explanatory.
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)//check if list is full if not add head
{
    if (listSize >= arrayCapacity){
        return;
    }
    for (int i = listSize; i > 0; i--){
        aList[i] = aList[i-1];
    }
    aList[0]=thisPos;
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos) //check if list is full if not add tail
{
    if (listSize >= arrayCapacity){
        return;
    }
    aList[listSize]=thisPos;
    listSize++;
}

void objPosArrayList::removeHead() //check if list is empty if not remove head
{
    if (listSize <= 0){
        return;
    }
    for (int i = 0; i < listSize  - 1; i++){
        aList[i] = aList[i+1];
    }
    listSize--;
}

void objPosArrayList::removeTail()
{
    if (listSize <= 0){
        return;
    }
   
    listSize--;
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize-1];
}

objPos objPosArrayList::getElement(int index) const
{
    return aList[index];
}