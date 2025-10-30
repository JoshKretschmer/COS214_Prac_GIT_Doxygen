#ifndef ITERATOR_H
#define ITERATOR_H

#include "Plant.h"
#include "Inventory.h"
#include <vector>

class Plant;
class Inventory;

class Iterator {
public:
    virtual ~Iterator() {}
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool hasNext() = 0;
    virtual Plant* currentItem() = 0;
};

class InventoryIterator : public Iterator {//own file
private:
    std::vector<Plant*> plants;//used to be Inventory* inventory;
    int currentIndex;
public:
    InventoryIterator(Inventory* inventory);
    void first() override;
    void next() override;
    bool hasNext() override;
    Plant* currentItem() override;
};

#endif //ITERATOR_H

