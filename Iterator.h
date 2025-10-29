#ifndef ITERATOR_H
#define ITERATOR_H

#include "Plant.h"
#include "Inventory.h"

class Plant;
class Inventory;

class Iterator {
public:
    Iterator();
    virtual ~Iterator();
    virtual bool hasNext();
    virtual Plant* next();
};

class InventoryIterator : public Iterator {
private:
    Inventory* inventory;
    int currentIndex;
public:
    InventoryIterator(Inventory* inventory);
    Plant* next();
    bool hasNext();
};



#endif //ITERATOR_H

