#include "InventoryClerk.h"
#include "Request.h"
#include "Plant.h"
#include "InventoryIterator.h"
#include <iostream>

/*!
 * @brief executes the specified Command
 *
 * Either adding a Plant to inventory, removing it from inventory, or returning a description of the contents of Inventory
 *
 * @param command Command object containing the Request to be run
 */
void InventoryClerk::executeTask(Command *command)
{
    std::cout << "Calling InventoryClerk::executeTask(command="
              << (command ? command->getRequest()->getPlantID() : "null") << ")\n";

    if (command->getRequest()->getType() != "inventory")
    {
        std::cout << "InventoryClerk::executeTask() - not an inventory command, forwarding\n";
        forwardCommand(command);
        return;
    }

    std::cout << "InventoryClerk::executeTask() setting receiver to " << staffName << "\n";
    command->getRequest()->setReceiver(this);
    Request *request = command->execute();

    std::cout << "InventoryClerk::executeTask() completed\n";
}

/*!
 * @brief Basic constuctor function
 *
 * @param _name name of staff member
 */
InventoryClerk::InventoryClerk(std::string _name) : Staff(_name)
{
    std::cout << "Calling InventoryClerk Constructor (name=\"" << _name << "\")\n";
    staffType = "inventoryclerk";
    inventory = nullptr;
    std::cout << "InventoryClerk Constructor set staffType to \"inventoryclerk\"\n";
}

/*!
 * @brief Basic destructor function
 */
InventoryClerk::~InventoryClerk()
{
    std::cout << "Calling InventoryClerk Deconstructor (ID=" << staffID << ")\n";
    inventory = nullptr;
}

/*!
 * @param _inventory Inventory object that the Clerk is able to interact with
 */
void InventoryClerk::assignJob(Inventory *_inventory)
{
    std::cout << "Calling InventoryClerk::assignJob(inventory="
              << (_inventory ? "non-null" : "null") << ")\n";
    inventory = _inventory;
    std::cout << "InventoryClerk::assignJob() assigned inventory\n";
}

/*!
 * @param plant Plant object to be added to the Inventory
 */
void InventoryClerk::storePlant(Plant *plant)
{
    std::cout << "Calling InventoryClerk::storePlant(plant="
              << (plant ? plant->getDetails() : "null") << ")\n";

    this->inventory->addPlant(plant);

    std::cout << "InventoryClerk::storePlant() added plant to inventory\n";
}

/*!
 * @param plantID id of the plant to be fetched from the inventory
 * @return Plant object that has been fetched
 */
Plant *InventoryClerk::getPlant(std::string plantID)
{
    std::cout << "Calling InventoryClerk::getPlant(plantID=\"" << plantID << "\")\n";

    if (!inventory)
    {
        std::cout << "InventoryClerk::getPlant() returning nullptr (no inventory)\n";
        return nullptr;
    }

    Iterator *it = new InventoryIterator(inventory);
    Plant *foundPlant = nullptr;

    while (it->hasNext())
    {
        Plant *current = it->currentItem();
        if (current->getID() == plantID)
        {
            foundPlant = current;
            std::cout << "InventoryClerk::getPlant() found plant: "
                      << foundPlant->getDetails() << "\n";
            break;
        }
        it->next();
    }
    delete it;

    if (!foundPlant)
    {
        std::cout << "Plant not found in inventory.\n";
        std::cout << "InventoryClerk::getPlant() returning nullptr\n";
        return nullptr;
    }

    inventory->removePlant(plantID);
    std::cout << "InventoryClerk::getPlant() removed plantID=\"" << plantID
              << "\" and returning plant\n";
    return foundPlant;
}