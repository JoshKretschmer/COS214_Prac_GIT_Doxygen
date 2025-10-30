#include "Horticulturist.h"

/*!
 *
 * @param command Command object containing request to be executed
 */
void Horticulturist::executeTask(Command* command)
{
    Request* request = command->execute();
    request->getID();

    // types of request it had do is yet to be discussed
    //Plant creation request?
}

/*!
 * @brief Basic constructor
 *
 * @param name Name of new Horticulturist
 */
Horticulturist::Horticulturist(string name) : Staff(name)
{
    staffName = "horticulturist";
}

/*!
 * @brief Basic destructor
 */
Horticulturist::~Horticulturist()
{
    //no memory management as of yet
}

/*!
 * @brief Sends a request to move the specified Plant to Inventory
 *
 * Creates a new request, encapsulates it in a command, and sends it to be handled by the relevant Staff
 *
 * @param plant Plant to be moved to Inventory
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