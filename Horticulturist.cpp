#include "Horticulturist.h"

void Horticulturist::executeTask(Command* command)
{
    Request* request = command->execute();
    request->getID();

    // types of request it had do is yet to be discussed :)
}

Horticulturist::Horticulturist(string name) : Staff(name)
{
    staffName = "horticulturist";
}

Horticulturist::~Horticulturist()
{
    //no memory management as of yet
}

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