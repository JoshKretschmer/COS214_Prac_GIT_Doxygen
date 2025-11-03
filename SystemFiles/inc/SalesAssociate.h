#ifndef SALESASSOCIATE_H
#define SALESASSOCIATE_H

#include "Staff.h"

/*!
 * @class SalesAssociate
 *
 * @brief public Staff class responsible for interacting with customer and passing on their requests
 */
class SalesAssociate : public Staff
{
private:
    virtual void executeTask(Command* command) override;

public:
    SalesAssociate(string _name);
    ~SalesAssociate();
};




#endif