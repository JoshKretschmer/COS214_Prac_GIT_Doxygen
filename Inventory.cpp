#include "Inventory.h"

Inventory::Inventory(int _shelfCapacity)
{
    shelves = new Shelf *[3];

    shelves[0] = new Shelf("FLOWER", _shelfCapacity);
    shelves[1] = new Shelf("SHRUB", _shelfCapacity);
    shelves[2] = new Shelf("SUCCULENT", _shelfCapacity);
}

Inventory::~Inventory()
{
    // yet to implement destructor. First validate the control of object flow
}

void Inventory::addBox(Box *_box, string _shelfName)
{
    for (int i = 0; i < 3; i++)
    {
        if (shelves[i]->getShelfName() == _shelfName)
        {
            shelves[i]->addBox(_box);
        }
    }
}

Box *Inventory::removeBox(string _boxID, string _shelfName)
{
    Box* actualBox = NULL;

    for (int i = 0; i < 3; i++)
    {
        if (shelves[i]->getShelfName() == _shelfName)
        {
            actualBox = shelves[i]->removeBox(_boxID);
        }
    }

    return actualBox;
}

void Inventory::peak()
{
    for (int i=0; i<3; i++)
    {
        shelves[i]->peak();
    }
}
