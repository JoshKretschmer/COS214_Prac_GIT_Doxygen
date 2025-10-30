#include "Command.h"

Command::Command(Request*_request)
{
    if(_request)
    {
        request = _request;
    }
    else
    {
        cerr<<"requestQueue is NULL object...\nNothing initialized";
    }
}

Command::~Command()
{
    // no memory management required as Command is not responsible for Request object once it is passed on :)
    // only null the pointer
}

bool Command::hasAccess(string _staffType)
{
    if(access == _staffType)
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
        cerr<<"request queue not set\nNULL returned...";
        return NULL;
    }
}