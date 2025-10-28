#ifndef INVENTORYCLERK_H
#define INVENTORYCLERK_H

/*!
 * @headerfile InventoryClerk.h
 */

#include "libraries.h"
#include "Staff.h"
#include "Inventory.h"
#include "Request.h"

/*!
 * @class InventoryClerk
 *
 * @brief Public child of Staff class
 *
 * Specifically responsible for the access and organization of plant objects in the Inventory
 */
class InventoryClerk : public Staff
{
private:
    Inventory *inventory;

    void addBox(Box *_box, string _shelfName);
    Box *removeBox(string _boxID, string _shelfName);
    Plant *unboxPlant(string _boxID, string _shelfName);

    virtual void executeTask(Command* command) override;
    // virtual void handleRequest(Request *request) override;

public:
    InventoryClerk(string _name);
    virtual ~InventoryClerk();

    void storePlant(Plant* plant);
   // virtual void peak() override;

    // can implement Mediator here

    void assignJob(Inventory *_inventory);
};

#endif