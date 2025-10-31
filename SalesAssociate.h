#ifndef SALESASSOCIATE_H
#define SALESASSOCIATE_H

#include "Staff.h"
#include "Command.h"

/*!
 * @class SalesAssociate
 *
 * @brief public Staff class responsible for managing client info and purchase requests
 */
class SalesAssociate : public Staff
{
private:
    void executeTask(Command* command) override;

public:
    SalesAssociate(std::string _name, Staff* clerk);
    ~SalesAssociate();
};




#endif