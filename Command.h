#ifndef COMMAND_H
#define COMMAND_H
/*!
 * @headerfile Command.h
 */

#include "libraries.h"
#include "Request.h"

class Request;

/*!
 * @class Command
 *
 * @brief Parent class for all kinds of commands
 *
 * Stores access specification string and an associated request
 */
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

/*!
 * @class SalesCommand
 *
 * @brief Commands created by Staff objects of type SalesAssociate
 */
class SalesCommand : public Command
{
public:
    SalesCommand(Request *_request);
    ~SalesCommand();
};

/*!
 * @class InventoryCommand
 *
 * @brief Commands created by Staff objects of type InventoryClerk
 */
class InventoryCommand : public Command
{
public:
    InventoryCommand(Request *_request);
    ~InventoryCommand();
};

/*!
 * @class ManagerCommand
 *
 * @brief Commands created by Staff objects of type Manager
 */
class ManagerCommand : public Command
{
public:
    ManagerCommand(Request *_request);
    ~ManagerCommand();
};

/*!
 * @class GreenHouseCommand
 *
 * @brief Commands created by Staff objects of type Horticulturist
 */
class GreenHouseCommand : public Command
{
public:
    GreenHouseCommand(Request *_request);
    ~GreenHouseCommand();
};

#endif