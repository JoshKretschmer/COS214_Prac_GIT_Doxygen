#include "InventoryClerk.h"

void InventoryClerk::executeTask(Command* command)
{
    Request* task = command->execute();

    if(task->getAction() == "STOREPLANT")
    {
        storePlant(task->getPlantObject());
    }   
}

void InventoryClerk::addBox(Box* _box, string _shelfName)
{
    inventory->addBox(_box,_shelfName);
}

Box* InventoryClerk::removeBox(string _boxID, string _shelfName)
{
    Box* clerkBox = inventory->removeBox(_boxID,_shelfName);

    if(!clerkBox)
    {
        cout<<"\n Box with ID: "<<_boxID<<" not removed. NULL returned.\n";
    }
    
    return clerkBox;
}

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

InventoryClerk::InventoryClerk(string _name) : Staff(_name)
{
    staffType = toUpperCase("inventoryclerk");
    inventory = NULL;
}

InventoryClerk::~InventoryClerk()
{
    inventory = NULL;
}

void InventoryClerk::assignJob(Inventory* _inventory)
{
    inventory = _inventory;
}

void InventoryClerk::storePlant(Plant * plant)
{
    Box* box = new Box(plant);
    string plantGroup = plant->getPlantGroup();
    addBox(box,plantGroup);
}