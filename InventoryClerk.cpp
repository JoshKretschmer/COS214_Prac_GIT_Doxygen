#include "InventoryClerk.h"

void InventoryClerk::executeTask(Command* command)
{
    //Depends on how command/request is implemented
}

/*!
 * @brief Basic constuctor function
 *
 * @param _name name of staff member
 */
InventoryClerk::InventoryClerk(string _name) : Staff(_name)
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
void InventoryClerk::assignJob(Inventory* _inventory)
{
    inventory = _inventory;
}

/*!
 * @param plant Plant object to be added to the Inventory
 */
void InventoryClerk::storePlant(Plant * plant)
{
    this->inventory->addPlant(plant);
}

/*!
 * @param plantID id of the plant to be fetched from the inventory
 * @return Plant object that has been fetched
 */
Plant * InventoryClerk::getPlant(string plantID) {

    //find plant
    Iterator* it = new InventoryIterator(inventory);
    Plant* returnPlant = NULL;

    while (it->hasNext()) {
        if (it->currentItem()->getID() == plantID) {
            returnPlant = it->currentItem();
        }
        it->next();
    }

    if (returnPlant != NULL) {
        cout << "Plant does not exist in inventory";
        return returnPlant;
    }

    //remove from inventory
    this->inventory->removePlant(plantID);

    //return plant
    return returnPlant;
}
