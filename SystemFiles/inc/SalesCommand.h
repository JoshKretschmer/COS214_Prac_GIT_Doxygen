#ifndef SALESCOMMAND_H
#define SALESCOMMAND_H

#include "Command.h"

/*!
 * @class SalesCommand
 *
 * @brief Commands to be handled by The SalesAssociate, wjo acts as a middleman between Customer and InventoryClerk
 */
class SalesCommand : public Command
{
public:
    SalesCommand(Request *_request);
    ~SalesCommand();
    Request* execute();
};



#endif //SALESCOMMAND_H
