#ifndef INVENTORYCLERK_H
#define INVENTORYCLERK_H

#include "Command.h"
#include "Staff.h"
#include "Inventory.h"
#include "Request.h"

class InventoryClerk : public Staff
{
private:
    Inventory *inventory;
    void executeTask(Command* command) override;

public:
    InventoryClerk(string _name);
    ~InventoryClerk();
    void storePlant(Plant* plant);
    Plant* getPlant(string plantID);
    void assignJob(Inventory *_inventory);
};

#endif //INVENTORYCLERK_H