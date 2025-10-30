#include "GreenHouseCommand.h"

GreenHouseCommand::GreenHouseCommand(Request *_request) : Command(_request)
{
    access = "horticulturist";
}

GreenHouseCommand::~GreenHouseCommand()
{
    // no memory management required as Command is not responsible for Request object once it is passed on :)
}