#include "Command.h"

Command::Command(Request *_request)
{
    request = _request;
}

Command::~Command()
{
}

bool Command::hasAccess(std::string _staffType)
{
    return (_staffType == access);
}

