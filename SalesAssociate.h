#ifndef SALESASSOCIATE_H
#define SALESASSOCIATE_H

#include "libraries.h"
#include "Staff.h"
#include "Command.h"


class SalesAssociate : public Staff
{
private:
    virtual void executeTask(Command* command) override;

public:
    SalesAssociate(string _name);
    ~SalesAssociate();
};




#endif