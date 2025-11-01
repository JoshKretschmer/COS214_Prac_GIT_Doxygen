#include "../inc/SalesAssociate.h"
#include "../inc/Customer.h"
#include "../inc/Command.h"
#include "../inc/Request.h"
#include <iostream>

/*!
 * @brief Basic constructor
 *
 * @param _name name of Staff member
 */
SalesAssociate::SalesAssociate(std::string _name) : Staff(_name)
{
    std::cout << "Calling SalesAssociate Constructor (name=\"" << _name << "\")\n";
    staffType = "SalesAssociate";
}

/*!
 * @brief Basic destructor for sales associate
 */
SalesAssociate::~SalesAssociate()
{
}

/*!
 * @param command Command object containing request to be executed
 */
void SalesAssociate::executeTask(Command *command)
{
    std::cout << "Calling SalesAssociate::executeTask(command="
              << (command ? command->getRequest()->getPlantID() : "null") << ")\n";

    if (command->getRequest()->getType() != "sales")
    {
        std::cout << "SalesAssociate::executeTask() - not a sales command, forwarding\n";
        forwardCommand(command);
        return;
    }

    std::cout << "SalesAssociate::executeTask() setting receiver to " << staffName << "\n";
    command->getRequest()->setReceiver(this);
    command->execute();

    std::cout << "SalesAssociate::executeTask() completed\n";
}