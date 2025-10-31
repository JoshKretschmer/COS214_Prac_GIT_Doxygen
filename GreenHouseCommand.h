#ifndef GREENHOUSECOMMAND_H
#define GREENHOUSECOMMAND_H

#include "Command.h"
#include "Horticulturist.h"

class GreenHouseCommand : public Command
{
public:
    GreenHouseCommand(Request *_request);
    ~GreenHouseCommand();
    Request* execute();
};



#endif //GREENHOUSECOMMAND_H
