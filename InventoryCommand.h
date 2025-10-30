#ifndef INVENTORYCOMMAND_H
#define INVENTORYCOMMAND_H

#include "Command.h"

class InventoryCommand : public Command
{
public:
    InventoryCommand(Request *_request);
    ~InventoryCommand();
    Request* InventoryCommand::execute()
};



#endif //INVENTORYCOMMAND_H
