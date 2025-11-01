#ifndef INVENTORYCOMMAND_H
#define INVENTORYCOMMAND_H

#include "Command.h"
#include "InventoryClerk.h"

/*!
 * @class InventoryCommand
 *
 * @brief Contains requests to add, remove, and fetche objects from Inventory
 */
class InventoryCommand : public Command
{
public:
    InventoryCommand(Request *_request);
    ~InventoryCommand();
    Request* execute();
};

#endif //INVENTORYCOMMAND_H
