#ifndef INVENTORYITERATOR_H
#define INVENTORYITERATOR_H

#include "Iterator.h"

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

#endif //INVENTORYITERATOR_H
