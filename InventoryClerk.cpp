#include "InventoryClerk.h"

/*!
 * @brief Fetches the task from the Command object and executes it
 *
 * @param command Contains a task Command that the Clerk has to do
 */
void InventoryClerk::executeTask(Command* command)
{
    Request* task = command->execute();

    if(task->getAction() == "STOREPLANT")
    {
        storePlant(task->getPlantObject());
    }   
}

/*!
 * @brief Adds an object to the Inventory
 *
 * @param _box Box object that needs to be stored
 * @param _shelfName Specifies the catgory/Shelf on whi9ch to store the Box
 */
void InventoryClerk::addBox(Box* _box, string _shelfName)
{
    inventory->addBox(_box,_shelfName);
}

/*!
 * @param _boxID Box to be removed from inventory
 * @param _shelfName Category/Shelf in which the Box will be searched for
 * @return specified Box with its contents, NULL if such box does not exist
 */
Box* InventoryClerk::removeBox(string _boxID, string _shelfName)
{
    Box* clerkBox = inventory->removeBox(_boxID,_shelfName);

    if(!clerkBox)
    {
        cout<<"\n Box with ID: "<<_boxID<<" not removed. NULL returned.\n";
    }
    
    return clerkBox;
}

/*!
 *
 * @param _boxID Box containing the desired Plant
 * @param _shelfName Category/Shelf that the Plant object belongs to
 * @return Plant object that was stored in the Box object
 */
Plant* InventoryClerk::unboxPlant(string _boxID, string _shelfName)
{
    Box* clerkBox = inventory->removeBox(_boxID,_shelfName);
    Plant* plantInBox = clerkBox->unboxPlant();

    if(!plantInBox)
    {
        cout<<"\n Box with ID: "<<_boxID<<" did not contain any plants. NULL returned.\n";
    }

    delete clerkBox;
    return plantInBox;
}

/*void InventoryClerk::peak()
{
    inventory->peak();
}*/

/*!
 * @brief Basic creator function
 *
 * @param _name Name of the staff Object
 */
InventoryClerk::InventoryClerk(string _name) : Staff(_name)
{
    staffType = toUpperCase("inventoryclerk");
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
 *
 * @param _inventory Specifies the Inventory Object that this Clerk is able to interact with
 */
void InventoryClerk::assignJob(Inventory* _inventory)
{
    inventory = _inventory;
}

/*!
 * @brief Creates a Box object, stores the Plant therein, and then stores the box in Inventory on the correct Shelf
 *
 * @param plant Plant Object to be stored
 */
void InventoryClerk::storePlant(Plant * plant)
{
    Box* box = new Box(plant);
    string plantGroup = plant->getPlantGroup();
    addBox(box,plantGroup);
}