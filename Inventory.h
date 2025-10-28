#ifndef INVENTORY_H
#define INVENTORY_H

/*!
 * @headerfile Inventory.h
 */

#include "libraries.h"
#include "Shelf.h"

/*!
 * @class Inventory
 *
 * @brief Stores Shelf objects containing boxes of plants
 *
 * Managed by InventoryClerk which allows the rest of the system to access plants. Allows for easy organized adding, removing, and bookkeeping of plants
 */
class Inventory
{
private:
    Shelf **shelves; //fixed at 3 shelves (Flower, Succulent, Shrub)
public:
    Inventory(int _shelfCapacity);
    ~Inventory();
    void addBox(Box* _box, string _shelfName);
    Box* removeBox(string _boxID, string _shelfName);
    void peak();
};

#endif //INVENTORY_H
