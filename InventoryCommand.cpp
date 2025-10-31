#include "InventoryCommand.h"
#include "Request.h"

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
Request* InventoryCommand::execute()
{
    //now I simply want to print the information of the plant
    //how do I navigate the inventory from here?
    Staff* receiver = request->getReceiver();
    InventoryClerk* clerk = dynamic_cast<InventoryClerk*>(receiver);
    Plant* plant = clerk->getPlant(request->getPlantID());
    if (plant != nullptr){
        std::cout << plant->getDetails() << std::endl;
    }else{
        std::cout << "Plant not found in inventory." << std::endl;
    }

    return nullptr;
}