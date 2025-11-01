#include "Staff.h"
#include "Command.h"
#include "Plant.h"
#include "Request.h"
#include <iostream>

int Staff::instanceCount = 1;

/*!
 * @brief Basic constructor for general Staff
 *
 * @param _name value for staffName attribute
 */
Staff::Staff(std::string _name)
{
    std::cout << "Calling Staff Constructor (name=\"" << _name << "\")\n";
    staffName = _name;
    staffID = "STAFF" + std::to_string(instanceCount);
    instanceCount++;
    nextHandler = nullptr;
    std::cout << "Staff Constructor created " << staffID << "\n";
}

/*!
 * @brief Basic destructor for general Staff
 */
Staff::~Staff()
{
    std::cout << "Calling Staff Deconstructor (ID=" << staffID << ")\n";
    nextHandler = nullptr;
    instanceCount--;
}

/*!
 *
 * @param _handler Next Staff object in chain of command
 */
void Staff::setNextHandler(Staff *_handler)
{
    std::cout << "Calling Staff::setNextHandler(handler="
              << (_handler ? _handler->getStaffName() : "null") << ")\n";
    nextHandler = _handler;
    std::cout << "Staff::setNextHandler() set nextHandler to "
              << (nextHandler ? nextHandler->getStaffName() : "null") << "\n";
}

/*!
 * @brief Sends the Command object to the nextHandler Staff object
 *
 * @param command Command object to be forwarded
 */
void Staff::forwardCommand(Command *command)
{
    std::cout << "Calling Staff::forwardCommand(command="
              << (command ? command->getRequest()->getPlantID() : "null") << ")\n";

    if (nextHandler)
    {
        std::cout << "Staff::forwardCommand() forwarding to "
                  << nextHandler->getStaffName() << "\n";
        nextHandler->handleCommand(command);
    }
    else
    {
        std::cerr << "NO next handler for " << staffName
                  << "... Request not handled...\n";
    }
}

/*!
 *
 * @param _command Command object containing request to be executed
 */
void Staff::executeTask(Command *_command)
{
    std::cout << "Calling Staff::executeTask(command="
              << (_command ? _command->getRequest()->getPlantID() : "null") << ")\n";
    std::cout << "Staff::executeTask() - no action (base class)\n";
}

/*!
 * @brief Checks if this Staff can handle the Command, if not the Command is forwarded
 *
 * @param command Command object to be executed
 */
void Staff::handleCommand(Command *command)
{
    std::cout << "Calling Staff::handleCommand(command="
              << (command ? command->getRequest()->getPlantID() : "null") << ")\n";

    if (command->hasAccess(staffType))
    {
        std::cout << "Staff::handleCommand() - " << staffName
                  << " has access, executing task\n";
        executeTask(command);
    }
    else
    {
        std::cout << "Staff::handleCommand() - " << staffName
                  << " does not have access, forwarding\n";
        forwardCommand(command);
    }
}

/*!
 * @brief Template Method implementation
 *
 * @param plant Plant object to be moved to Inventory
 */
void Staff::movePlantToInventory(Plant *plant)
{
    std::cout << "Calling Staff::movePlantToInventory(plant="
              << (plant ? plant->getDetails() : "null") << ")\n";
    std::cout << "Staff::movePlantToInventory() - no action (base class)\n";
}