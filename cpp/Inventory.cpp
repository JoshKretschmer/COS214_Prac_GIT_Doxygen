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


InventoryIterator* Inventory::createIterator() {
    return new InventoryIterator(this);
}

Shelf** Inventory::getShelves() {
    return shelves;
}

bool Inventory::isPresent(std::string plantType) {
    if (!it){
        it = createIterator();
    }
    it->reset();
    bool found = false;

    while (it->hasNext()) {
        Plant* plant = it->next();
        if (plant && toUpperCase(plant->getPlantType()) == toUpperCase(plantType)) {
            
            found = true;
            break;
        }
    }
    return found;
}