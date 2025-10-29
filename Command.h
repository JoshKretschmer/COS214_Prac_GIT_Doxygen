#ifndef COMMAND_H
#define COMMAND_H

#include "libraries.h"
#include "Request.h"

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
    bool hasAcess(string _staffType);
};

class SalesCommand : public Command
{
public:
    SalesCommand(Request *_request);
    ~SalesCommand();
};

class InventoryCommand : public Command
{
public:
    InventoryCommand(Request *_request);
    ~InventoryCommand();
};

class ManagerCommand : public Command
{
public:
    ManagerCommand(Request *_request);
    ~ManagerCommand();
};

class GreenHouseCommand : public Command
{
public:
    GreenHouseCommand(Request *_request);
    ~GreenHouseCommand();
};

#endif