#include "Shelf.h"

Shelf::Shelf(string _shelfName, int _shelfCapacity)
{
    shelfName = _shelfName;
    shelfCapacity = _shelfCapacity;
    boxes = new vector<Box*>();
}

Shelf::~Shelf()
{
    // how we handle memory will depend on the flow of control of objects
}

vector<Box*> Shelf::getBoxes()
{
    return *boxes; //must not that boxes still points to the vector of boxes
}

void Shelf::addBox(Box* _box)
{
    int numBoxes = boxes->size();

    if(numBoxes<shelfCapacity)
    {
        boxes->push_back(_box);
    }
    else
    {
        cout<<"\nCould not add Box to shelf. Limit reached: "<<numBoxes<<"/"<<shelfCapacity<<endl;
    }
}

Box* Shelf::removeBox(string _boxID)
{
    //ITERATOR PATTERN HERE

    Box* actualBox = NULL; //in case the box is not present in the shelf

    if(boxes)
    {
        int numBoxes = boxes->size();

        if(numBoxes>=1)
        {
            for(int i=0; i<numBoxes; i++)
            {
                if((*boxes)[i]->getBoxID() == _boxID)
                {
                    cout<<"\nBox with ID: "<<(*boxes)[i]->getBoxID()<<" removed from shelf: "<<shelfName<<endl;
                    actualBox = (*boxes)[i];
                }
            }
        }
        else
        {
            cout<<"\n"<<shelfName<<" has no boxes...\nNo box removed...\n";
        }
    }
    else
    {
        cout<<"\nThis shelf has not been structured to hold boxes...\nNo box removed...\n";
    }
    
    return actualBox;
}

void Shelf::peak()
{
    if(boxes)
    {
        int numBoxes = boxes->size();

        cout<<"\n------"<<shelfName<<"------"<<endl;

        for(int i=0; i<numBoxes; i++)
        {
            (*boxes)[i]->peak();
        } 

        cout<<"\n--------------------\n";
    }
    else
    {
        cout<<"\nThis shelf has not been structured to hold boxes...\nCannot peak shelf";
    }
}

string Shelf::getShelfName()
{
    return shelfName;
}