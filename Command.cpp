#include "Command.h"

/*!
 * @brief Creator for the Command object, objects must contain a request
 *
 * @param _request Request object to be forwarded with the command
 */
Command::Command(Request*_request)
{
    if(_request)
    {
        request = _request;
    }
    else
    {
        cout<<errorMessage("requestQueue is NULL object...\nNothign initialized");
    }
}

/*!
 * @brief Basic Destuctor for the Command object
 */
Command::~Command()
{
    // no memory management required as Command is not responsible for Request object once it is passed on :)
    // only null the pointer
}

/*!
 * @param _staffType Specifies the type of Staff Object to test for access
 * @return true if the specified Staff object is able to access and execute the command
 */
bool Command::hasAcess(string _staffType)
{
    if(access == toUpperCase(_staffType))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*!
 * @return The Request object to be run, if any is set
 */
Request* Command::execute()
{
    if(request)
    {
        return request;
    }
    else
    {
        cout<<errorMessage("request queue not set\nNULL returned...");
        return NULL;
    }
}


/*!
 * @brief Basic constructor, sets which type of Staff object can execute the command
 *
 * @param _request Request object to be forwarded with the command
 */
InventoryCommand::InventoryCommand(Request *_request) : Command(_request)
{
    access = toUpperCase("inventoryclerk");
}

/*!
 * Basic destructor for InventoryCommand
 */
InventoryCommand::~InventoryCommand()
{
    // no memory management required as Command is not responsible for Request object once it is passed on :)
}

//....................

/*!
 * @brief Basic constructor, sets which type of Staff object can execute the command
 *
 * @param _request Request object to be forwarded with the command
 */
SalesCommand::SalesCommand(Request *_request) : Command(_request)
{
    access = toUpperCase("salesassociate");
}

/*!
 * Basic destructor for SalesCommand
 */
SalesCommand::~SalesCommand()
{
    // no memory management required as Command is not responsible for Request object once it is passed on :)
}

//.....................

/*!
 * @brief Basic constructor, sets which type of Staff object can execute the command
 *
 * @param _request Request object to be forwarded with the command
 */
ManagerCommand::ManagerCommand(Request *_request) : Command(_request)
{
    access = toUpperCase("manager");
}

/*!
 * Basic destructor for ManagerCommand
 */
ManagerCommand::~ManagerCommand()
{
    // no memory management required as Command is not responsible for Request object once it is passed on :)
}

//......................

/*!
 * @brief Basic constructor, sets which type of Staff object can execute the command
 *
 * @param _request Request object to be forwarded with the command
 */
GreenHouseCommand::GreenHouseCommand(Request *_request) : Command(_request)
{
    access = toUpperCase("horticulturist");
}

/*!
 * Basic destructor for GreenHouseCommand
 */
GreenHouseCommand::~GreenHouseCommand()
{
    // no memory management required as Command is not responsible for Request object once it is passed on :)
}
