#ifndef SALESCOMMAND_H
#define SALESCOMMAND_H

#include "Command.h"

class SalesCommand : public Command
{
public:
    SalesCommand(Request *_request);
    ~SalesCommand();
    Request* execute();
};



#endif //SALESCOMMAND_H
