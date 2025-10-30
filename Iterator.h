#ifndef ITERATOR_H
#define ITERATOR_H


#include "Plant.h"
#include "Inventory.h"
#include <vector>

class Plant;
class Inventory;

class Iterator {
public:
    Iterator();
    virtual ~Iterator() {}
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool hasNext() = 0;
    virtual Plant* currentItem() = 0;
};

#endif //ITERATOR_H
