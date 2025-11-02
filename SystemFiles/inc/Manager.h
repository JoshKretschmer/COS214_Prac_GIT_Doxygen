#ifndef MANAGER_H
#define MANAGER_H

#include "Staff.h"

/*!
 * @class Manager
 *
 * @brief public Staff class responsible for handling commands that other Staff members cannot
 */
class Manager : public Staff
{
public:
    Manager(std::string _name);
    ~Manager();
    void executeTask(Command *command) override;
};

#endif // MANAGER_H