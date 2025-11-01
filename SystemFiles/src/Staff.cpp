#include "../inc/Staff.h"
#include "../inc/Command.h"
#include "../inc/Plant.h"
#include "../inc/Request.h"
#include <iostream>

int Staff::instanceCount = 1;

/*!
 * @brief Basic constructor for general Staff
 *
 * @param _name value for staffName attribute
 */
Staff::Staff(std::string _name)
{
    staffName = _name;
    staffID = "STAFF" + std::to_string(instanceCount);
    instanceCount++;
    nextHandler = nullptr;
}

/*!
 * @brief Basic destructor for general Staff
 */
Staff::~Staff()
{
    nextHandler = nullptr;
    instanceCount--;
}

/*!
 *
 * @param _handler Next Staff object in chain of command
 */
void Staff::setNextHandler(Staff *_handler)
{
    nextHandler = _handler;
}

/*!
 * @brief Sends the Command object to the nextHandler Staff object
 *
 * @param command Command object to be forwarded
 */
void Staff::forwardCommand(Command *command)
{
    if (nextHandler)
    {
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
    if (command->hasAccess(staffType))
    {
        executeTask(command);
    }
    else
    {
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