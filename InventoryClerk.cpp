#include "InventoryClerk.h"

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

    return plantInBox;
}

void InventoryClerk::peak()
{
    inventory->peak();
}

InventoryClerk::InventoryClerk(string _name) : Staff(_name)
{
    inventory = NULL;
    staffMembers = new vector<Staff*>();
}

InventoryClerk::~InventoryClerk()
{
    delete staffMembers;

    staffMembers = NULL;
    inventory = NULL;
    nextHander = NULL;
}

void InventoryClerk::assignJob(Inventory* _inventory)
{
    inventory = _inventory;
}