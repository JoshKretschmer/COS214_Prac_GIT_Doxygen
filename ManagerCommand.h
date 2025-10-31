#ifndef MANAGERCOMMAND_H
#define MANAGERCOMMAND_H

#include "Command.h"

class ManagerCommand : public Command
{
public:
    ManagerCommand(Request *_request);
    ~ManagerCommand();

    // Looks like this cause it needs to be able to handle anything and not just a specfifc thing
    Request *execute() override;
};

#endif // MANAGERCOMMAND_H
