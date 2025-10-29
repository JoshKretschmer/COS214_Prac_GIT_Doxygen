#ifndef INVENTORYCOMMAND_H
#define INVENTORYCOMMAND_H

#include "Command.h"

class InventoryCommand : public Command
{
public:
    InventoryCommand(Request* _request);
    ~InventoryCommand() override;
    Request* execute() override;
};

#endif // INVENTORYCOMMAND_H