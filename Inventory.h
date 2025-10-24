#ifndef INVENTORY_H
#define INVENTORY_H

#include "libraries.h"
#include "Shelf.h"

class Inventory
{
private:
    Shelf **shelves; //fixed at 3 shelves (Flower, Succalent, Shrub)
public:
    Inventory(int _shelfCapacity);
    ~Inventory();
    void addBox(Box* _box, string _shelfName);
    Box* removeBox(string _boxID, string _shelfName);
    void peak();
};

#endif //INVENTORY_H
