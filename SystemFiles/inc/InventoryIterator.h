#ifndef INVENTORYITERATOR_H
#define INVENTORYITERATOR_H

#include "Iterator.h"
#include <vector>
class Inventory;
class Plant;

/*!
 * @class InventoryIterator
 *
 * @brief Basic application of the iterator design pattern to step through the plants contained in an Inventory object
 */
class InventoryIterator : public Iterator
{
private:
    std::vector<Plant *> plants;
    std::size_t currentIndex; // changed from int

public:
    InventoryIterator(Inventory *inventory);
    void first() override;
    void next() override;
    bool hasNext() override;
    Plant *currentItem() override;
};

#endif // INVENTORYITERATOR_H
