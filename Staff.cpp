#include "Staff.h"

int Staff::instanceCount = 1;

/*!
 * @brief Basic constructor for general Staff
 *
 * @param _name value for staffName attribute
 */
Staff::Staff(string _name)
{
    staffName = _name;
    staffID = "STAFF"+to_string(instanceCount);
    instanceCount++;

    nextHandler = NULL;
}

/*!
 * @brief Basic destructor for general Staff
 */
Staff::~Staff()
{
    nextHandler = NULL;
    instanceCount--;
}

/*!
 *
 * @param _handler Next Staff object in chain of command
 */
void Staff::setNextHandler(Staff * _handler)
{
    nextHandler = _handler;
}

/*!
 * @brief Sends the Command object to the nextHandler Staff object
 *
 * @param command Command object to be forwarded
 */
void Staff::forwardCommand(Command* command)
{
    if(nextHandler)
    {
        nextHandler->handleCommand(command);
    }
    else
    {
        cerr<<"NO next handler for" + staffName + "... Request not handled...";
    }
}

/*!
 * @brief executes the specified Command
 *
 * @param _command Command object containing the Request to be run
 */
void Staff::executeTask(Command *_command) {
    //Need to wait for command/request to be implemented
}

/*!
 * @brief Checks if this Staff can handle the Command, if not the Command is forwarded
 *
 * @param command Command object to be executed
 */
void Staff::handleCommand(Command* command)
{
    if(command->hasAccess(staffType))
    {
        executeTask(command);
    }
    else
    {
        cout<<"\nstaff "<<staffName<<" does not have access to handleCommand...\n";
        forwardCommand(command);
    }
}

/*!
 * @brief Template method implementation
 *
 * @param plant Plant object to be moved to Inventory
 */
void Staff::movePlantToInventory(Plant* plant) {
    Request* request = new Request();
    request->setAction(getActionForMove());  
    request->setDescription(getDescriptionForMove()); 
    request->setPlantObject(plant);
    request->setSender(this);

    Command* command = new InventoryCommand(request);  //assuming InventoryCommand is a concrete Command subclass

    handleCommand(command);
}