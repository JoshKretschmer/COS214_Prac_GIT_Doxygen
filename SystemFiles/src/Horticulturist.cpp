#include "../inc/Horticulturist.h"
#include "../inc/Command.h"
#include "../inc/Request.h"
#include <iostream>

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

/*!
 * @brief Sends a request to move the specified Plant to Inventory
 *
 * Creates a new request, encapsulates it in a command, and sends it to be handled by the relevant Staff
 *
 * @param plant Plant to be moved to Inventory
 */
std::string Horticulturist::getActionForMove()
{
    std::cout << "Calling Horticulturist::getActionForMove()\n";
    std::string result = "";
    std::cout << "Horticulturist::getActionForMove() returning \"" << result << "\"\n";
    return result;
}

std::string Horticulturist::getDescriptionForMove()
{
    std::cout << "Calling Horticulturist::getDescriptionForMove()\n";
    std::string result = "just store the plant :)";
    std::cout << "Horticulturist::getDescriptionForMove() returning \"" << result << "\"\n";
    return result;
}