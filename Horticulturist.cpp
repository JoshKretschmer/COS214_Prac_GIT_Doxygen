#include "Horticulturist.h"

/*!
 *
 *
 * @param command Command object containing a request to be executed
 */
void Horticulturist::executeTask(Command* command)
{
    Request* request = command->execute();
    request->getID();

    // types of request it had do is yet to be discussed :)
}

/*!
 * @brief Creator function
 *
 * @param name Name of the staff member
 */
Horticulturist::Horticulturist(string name) : Staff(name)
{
    staffName = toUpperCase("horticulturist");
}

/*!
 * @brief Basic destructor
 */
Horticulturist::~Horticulturist()
{
    //no memory management as of yet
}

/*!
 * @brief Creates an inventoryCommand containing a request to add a Plant object to the Inventory
 *
 * @param plant Plant object to be moved
 */
void Horticulturist::movePlantToInventory(Plant* plant)
{
    Request* request = new Request();
    request->setAction(ACTION_STOREPLANT);
    request->setDescription("just store the plant :)");
    request->setPlantObject(plant);
    request->setSender(this);

    Command* command = new InventoryCommand(request);

    handleCommand(command);
}