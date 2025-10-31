#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class Request;
class Staff;

class Command
{
protected:
    std::string access;  // the staff member who can access a command 
    Request* request;

public:
    Command(Request *_request);
    virtual ~Command();
    virtual Request* execute() = 0;
    bool hasAccess(std::string _staffType);
    Request* getRequest() { return request; }
};

#endif