#ifndef SALESCOMMAND_H
#define SALESCOMMAND_H

#include "Command.h"

class SalesCommand : public Command
{
public:
    SalesCommand(Request *_request);
    ~SalesCommand();
};



#endif //SALESCOMMAND_H
