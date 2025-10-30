#include "ManagerCommand.h"

ManagerCommand::ManagerCommand(Request *_request) : Command(_request)
{
    access = "manager";
}

ManagerCommand::~ManagerCommand()
{
    // no memory management required as Command is not responsible for Request object once it is passed on :)
}