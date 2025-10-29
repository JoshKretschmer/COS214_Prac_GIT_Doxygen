#ifndef INVENTORY_H
#define INVENTORY_H

#include "libraries.h"
#include "Shelf.h"
#include "Iterator.h"

class Inventory
{
private:
    Shelf **shelves; //fixed at 3 shelves (Flower, Succalent, Shrub)
    InventoryIterator* it;
public:
    Inventory(int _shelfCapacity);
    ~Inventory();
    void addBox(Box* _box, string _shelfName);
    Box* removeBox(string _boxID, string _shelfName);
    void peak();
    bool isPresent(string PlantType);
    Shelf** getShelves();
    InventoryIterator* createIterator();
};

#endif //INVENTORY_H
