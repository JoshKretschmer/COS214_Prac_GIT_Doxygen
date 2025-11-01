#include "InventoryCommand.h"
#include "Request.h"
#include "Plant.h"
#include <iostream>

/*!
 * @brief Basic constructor function
 *
 * @param _request Request object to be contained
 */
InventoryCommand::InventoryCommand(Request *_request) : Command(_request)
{
    std::cout << "Calling InventoryCommand Constructor (request="
              << (_request ? _request->getPlantID() : "null") << ")\n";
    access = "inventoryclerk";
}

/*!
 * @brief Basic destructor function
 */
InventoryCommand::~InventoryCommand()
{
    std::cout << "Calling InventoryCommand Deconstructor\n";
}

/*!
 * @brief Executes the Request inside Command
 *
 * @return Details of Plants stored in inventory
 */
Request *InventoryCommand::execute()
{
    std::cout << "Calling InventoryCommand::execute()\n";

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