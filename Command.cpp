#include "Command.h"

Command::Command(Request *_request)
{
    request = _request;
}

Command::~Command()
{
}

bool Command::hasAccess(string _staffType)
{
    return (_staffType == access);
}

