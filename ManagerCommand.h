#ifndef MANAGERCOMMAND_H
#define MANAGERCOMMAND_H

#include "Command.h"

class ManagerCommand : public Command
{
public:
    ManagerCommand(Request *_request);
    ~ManagerCommand();
    Request* ManagerCommand::execute();
};



#endif //MANAGERCOMMAND_H
