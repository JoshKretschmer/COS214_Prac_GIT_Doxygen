#include "../inc/InventoryCommand.h"
#include "../inc/Request.h"
#include "../inc/Plant.h"
#include <iostream>

/*!
 * @brief Basic constructor function
 *
 * @param _request Request object to be contained
 */
InventoryCommand::InventoryCommand(Request *_request) : Command(_request)
{
    access = "inventoryclerk";
}

/*!
 * @brief Basic destructor function
 */
InventoryCommand::~InventoryCommand()
{
}

/*!
 * @brief Executes the Request inside Command
 *
 * @return Details of Plants stored in inventory
 */
Request *InventoryCommand::execute()
{
    Staff *receiver = request->getReceiver();
    InventoryClerk *clerk = dynamic_cast<InventoryClerk *>(receiver);
    Plant *plant = clerk->getPlant(request->getPlantID());

    if (plant != nullptr)
    {
        std::cout << "InventoryCommand::execute() found plant: "
                  << plant->getDetails() << "\n";
    }
    else
    {
        std::cout << "InventoryCommand::execute() - Plant not found in inventory.\n";
    }

    return nullptr;
}