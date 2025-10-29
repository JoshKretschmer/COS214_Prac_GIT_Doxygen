#ifndef ITERATOR_H
#define ITERATOR_H

class Inventory;

#include "Plant.h"
#include <vector>
#include <string>

class Iterator {
public:
    virtual ~Iterator() {}
    virtual bool hasNext() = 0;
    virtual Plant* next() = 0;
};

class InventoryIterator : public Iterator {
private:
    Inventory* inventory;
    int shelfIndex;
    int boxIndex;
public:
    explicit InventoryIterator(Inventory* inv);
    bool hasNext() override;
    Plant* next() override;
    void reset();
};

#endif // ITERATOR_H

