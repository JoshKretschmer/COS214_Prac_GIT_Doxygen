#ifndef INVENTORYCLERK_H
#define INVENTORYCLERK_H

#include "Staff.h"
#include "Inventory.h"
#include "InventoryIterator.h"
#include "Command.h"

/*!
 * @class InventoryClerk
 *
 * @brief public Staff class responsible for controlling all access to the Inventory object
 * Adds Plants to the Inventory and fetches (removes) them on request
 */
class InventoryClerk : public Staff
{
private:
    Inventory *inventory;
    void executeTask(Command* command) override;

public:
    InventoryClerk(std::string _name);
    ~InventoryClerk();
    void storePlant(Plant* plant);
    Plant* getPlant(std::string plantID);
    void assignJob(Inventory *_inventory);
};

#endif //INVENTORYCLERK_H