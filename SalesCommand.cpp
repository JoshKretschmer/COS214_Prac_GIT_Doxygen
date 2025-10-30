#include "SalesCommand.h"

SalesCommand::SalesCommand(Request *_request) : Command(_request)
{
    access = "salesassociate";
}

SalesCommand::~SalesCommand()
{
    // no memory management required as Command is not responsible for Request object once it is passed on :)
}