#ifndef COMMAND_H
#define COMMAND_H

#include "Request.h"
#include <string>
#include <iostream>
using namespace std;

class Request;
class Command
{
protected:
    string access;  // the staff member who can access a command
    Request* request;

public:
    Command(Request *_request);
    virtual ~Command();
    Request* execute();
    bool hasAccess(string _staffType);
};


#endif //COMMAND_H
