#include "Staff.h"

int Staff::instanceCount = 1;

Staff::Staff(string _name)
{
    staffName = _name;
    staffID = "STAFF"+to_string(instanceCount);
    instanceCount++;

    nextHandler = NULL;
}

Staff::~Staff()
{
    nextHandler = NULL;
    //Nothign to destruct as of yet
    instanceCount--;
}

void Staff::setNextHandler(Staff * _handler)
{
    nextHandler = _handler;
}

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