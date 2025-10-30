#ifndef COMMAND_H
#define COMMAND_H

#include "Request.h"
#include "Horticulturist.h"

class Request;

class Command
{
protected:
    string access;  // the staff member who can access a command 
    Request* request;

public:
    Command(Request *_request);
    virtual ~Command();
    virtual Request* execute() = 0;
    bool hasAccess(string _staffType);
    Request* getRequest() { return request; }
};

#endif