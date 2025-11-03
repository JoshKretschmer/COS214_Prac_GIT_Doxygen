#ifndef GREENHOUSECOMMAND_H
#define GREENHOUSECOMMAND_H

#include "Command.h"
#include "Horticulturist.h"

/*!
 * @class GreenHouseCommand
 *
 * @brief Contains requests to create, nurture, and manage plants before they are added to inventory
 */
class GreenHouseCommand : public Command
{
public:
    GreenHouseCommand(Request *_request);
    ~GreenHouseCommand();
    Request* execute();
};



#endif //GREENHOUSECOMMAND_H
