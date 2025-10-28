#include "Command.h"

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

Command::~Command()
{
    // no memory management required as Command is not responsible for Request object once it is passed on :)
    // only null the pointer
}

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






InventoryCommand::InventoryCommand(Request *_request) : Command(_request)
{
    access = toUpperCase("inventoryclerk");
}

InventoryCommand::~InventoryCommand()
{
    // no memory management required as Command is not responsible for Request object once it is passed on :)
}

//....................

SalesCommand::SalesCommand(Request *_request) : Command(_request)
{
    access = toUpperCase("salesassociate");
}

SalesCommand::~SalesCommand()
{
    // no memory management required as Command is not responsible for Request object once it is passed on :)
}

//.....................


ManagerCommand::ManagerCommand(Request *_request) : Command(_request)
{
    access = toUpperCase("manager");
}

ManagerCommand::~ManagerCommand()
{
    // no memory management required as Command is not responsible for Request object once it is passed on :)
}

//......................


GreenHouseCommand::GreenHouseCommand(Request *_request) : Command(_request)
{
    access = toUpperCase("horticulturist");
}

GreenHouseCommand::~GreenHouseCommand()
{
    // no memory management required as Command is not responsible for Request object once it is passed on :)
}
