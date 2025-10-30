#include "InventoryCommand.h"

InventoryCommand::InventoryCommand(Request *_request) : Command(_request)
{
    access = "inventoryclerk";
}

InventoryCommand::~InventoryCommand()
{
    // no memory management required as Command is not responsible for Request object once it is passed on :)
}