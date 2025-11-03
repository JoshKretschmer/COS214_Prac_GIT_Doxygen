#ifndef MANAGERCOMMAND_H
#define MANAGERCOMMAND_H

#include "Command.h"

/*!
 * @class ManagerCommand
 *
 * @brief Commands to be handled by The Manager, who is able to handle anything and not just one thing
 */
class ManagerCommand : public Command
{
public:
    ManagerCommand(Request *_request);
    ~ManagerCommand();

    // Looks like this cause it needs to be able to handle anything
    Request *execute() override;
};

#endif // MANAGERCOMMAND_H
