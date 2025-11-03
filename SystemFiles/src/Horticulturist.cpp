#include "../inc/Horticulturist.h"
#include "../inc/Command.h"
#include "../inc/Request.h"
#include "../inc/Plant.h"
#include <iostream>
#include <InventoryCommand.h>

/*!
 *
 * @param command Command object containing request to be executed
 */
void Horticulturist::executeTask(Command *command)
{
    std::cout << "Calling Horticulturist::executeTask(command="
              << (command ? command->getRequest()->getPlantID() : "null") << ")\n";

    if (command->getRequest()->getType() != "greenhouse")
    {
        std::cout << "Horticulturist::executeTask() - not a greenhouse command, forwarding\n";
        forwardCommand(command);
        return;
    }

    std::cout << "Horticulturist::executeTask() setting receiver to " << staffName << "\n";
    command->getRequest()->setReceiver(this);
    command->execute();
    std::cout << "Horticulturist::executeTask() completed\n";
}

/*!
 * @brief Basic constructor
 *
 * @param name Name of new Horticulturist
 */
Horticulturist::Horticulturist(std::string name) : Staff(name)
{
    staffType = "horticulturist";
}

/*!
 * @brief Basic destructor
 */
Horticulturist::~Horticulturist()
{
}