#include "Staff.h"

int Staff::instanceCount = 1;

/*!
 * @brief Basic constructor funtion
 *
 * @param _name name of staff object being created
 */
Staff::Staff(string _name)
{
    staffName = _name;
    staffID = "STAFF"+to_string(instanceCount);
    instanceCount++;

    nextHandler = NULL;
}

/*!
 * Basic destructor function
 */
Staff::~Staff()
{
    nextHandler = NULL;
    //Nothign to destruct as of yet
    instanceCount--;
}

/*!
 *
 * @param _handler sets the next staff object in the chain_of_command pattern
 */
void Staff::setNextHandler(Staff * _handler)
{
    nextHandler = _handler;
}

/*!
 *
 * @param command Command object to be forwarded to Staff object in nextHandler attribute
 */
void Staff::forwardCommand(Command* command)
{
    if(nextHandler)
    {
        nextHandler->handleCommand(command);
    }
    else
    {
        cout<<errorMessage("NO next handler for" + staffName + "... Request not handled...");
    }
}

/*!
 * @brief Checks if a staff member is capable of handling a request
 *
 * If yes, the command executes, else the command is passed on
 *
 * @param command Command to be executed
 */
void Staff::handleCommand(Command* command)
{
    if(command->hasAcess(staffType))
    {
        executeTask(command);
    }
    else
    {
        cout<<"\nstaff "<<staffName<<" does not have access to handleCommand...\n";
        forwardCommand(command);
    }
}