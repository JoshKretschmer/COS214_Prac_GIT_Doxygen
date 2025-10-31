#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class Request;
class Staff;

/*!
 * @class Command
 *
 * @brief Parent Class of the various specific command classes
 * Encapsulated a request inside an object to control access to it and allow for the passing of a request along the CoR
 */
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