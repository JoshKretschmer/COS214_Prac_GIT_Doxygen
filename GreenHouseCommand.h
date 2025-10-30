#ifndef GREENHOUSECOMMAND_H
#define GREENHOUSECOMMAND_H

#include "Command.h"

class GreenHouseCommand : public Command
{
public:
    GreenHouseCommand(Request *_request);
    ~GreenHouseCommand();
    Request* GreenHouseCommand::execute();
};



#endif //GREENHOUSECOMMAND_H
