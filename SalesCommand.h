#ifndef SALESCOMMAND_H
#define SALESCOMMAND_H

#include "Command.h"

class SalesCommand : public Command
{
public:
    SalesCommand(Request* _request);
    ~SalesCommand() override;
    Request* execute() override;
};

#endif // SALESCOMMAND_H