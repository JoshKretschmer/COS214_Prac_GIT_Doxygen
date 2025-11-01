#include "../inc/Manager.h"
#include "../inc/Command.h"
#include "../inc/Request.h"
#include <iostream>

/*!
 * @brief Constructor for Manager
 *
 * @param _name Name of the manager
 */
Manager::Manager(std::string _name) : Staff(_name)
{
    std::cout << "Calling Manager Constructor (name=\"" << _name << "\")\n";
    staffType = "manager";
    std::cout << "Manager Constructor set staffType to \"manager\"\n";
}

/*!
 * @brief Destructor for Manager
 */
Manager::~Manager()
{
    std::cout << "Calling Manager Deconstructor (ID=" << staffID << ")\n";
}

/*!
 * @brief Executes the command if this staff can handle it
 *
 * @param command The command to execute
 */
void Manager::executeTask(Command *command)
{
    std::cout << "Calling Manager::executeTask(command="
              << (command ? command->getRequest()->getPlantID() : "null") << ")\n";

    Request *req = command->getRequest();

    std::cout << "Manager " << staffName << " is now handling the request: ";
    std::cout << "Type='" << req->getType() << "', PlantID='" << req->getPlantID() << "'\n";

    req->setReceiver(this);
    Request *result = command->execute();

    if (result == nullptr)
    {
        std::cout << "Manager has processed the request.\n";
    }

    std::cout << "Manager::executeTask() completed\n";
}