#include "InventoryClerk.h"
#include "Request.h"
#include "Plant.h"

/*!
 * @brief executes the specified Command
 *
 * Either adding a Plant to inventory, removing it from inventory, or returning a description of the contents of Inventory
 *
 * @param command Command object containing the Request to be run
 */
void InventoryClerk::executeTask(Command *command)
{
    if (command->getRequest()->getType() != "inventory")
    {
        // Forward to next handler if not an inventory command
        forwardCommand(command);
        return;
    }
    command->getRequest()->setReceiver(this);
    Request *request = command->execute();
}

/*!
 * @brief Basic constuctor function
 *
 * @param _name name of staff member
 */
InventoryClerk::InventoryClerk(std::string _name) : Staff(_name)
{
    staffType = "inventoryclerk";
    inventory = NULL;
}

/*!
 * @brief Basic destructor function
 */
InventoryClerk::~InventoryClerk()
{
    inventory = NULL;
}

/*!
 * @param _inventory Inventory object that the Clerk is able to interact with
 */
void InventoryClerk::assignJob(Inventory *_inventory)
{
    inventory = _inventory;
}

/*!
 * @param plant Plant object to be added to the Inventory
 */
void InventoryClerk::storePlant(Plant *plant)
{
    this->inventory->addPlant(plant);
}

/*!
 * @param plantID id of the plant to be fetched from the inventory
 * @return Plant object that has been fetched
 */
Plant *InventoryClerk::getPlant(std::string plantID)
{
    if (!inventory)
        return nullptr;

    Iterator *it = new InventoryIterator(inventory);
    Plant *foundPlant = nullptr;

    while (it->hasNext())
    {
        Plant *current = it->currentItem();
        if (current->getID() == plantID)
        {
            foundPlant = current;
            break; // found it
        }
        it->next();
    }
    delete it; 

    if (!foundPlant)
    {
        std::cout << "Plant not found in inventory.\n";
        return nullptr;
    }

    // remove from inventory and return
    inventory->removePlant(plantID);
    return foundPlant;
}
