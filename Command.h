#ifndef COMMAND_H
#define COMMAND_H

#include "libraries.h"
#include <string>

class Request;

class Command
{
protected:
    std::string access;
    Request* request;

public:
    Command(Request* _request);
    virtual ~Command();
    virtual Request* execute() = 0;
    bool hasAccess(const std::string& _staffType) const;
};

#endif // COMMAND_H