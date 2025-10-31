#ifndef MANAGER_H
#define MANAGER_H

#include "Staff.h"

class Manager : public Staff
{
public:
    /*!
     * @brief Constructor for Manager
     * @param _name Name of the manager
     */
    Manager(std::string _name);

    /*!
     * @brief Destructor for Manager
     */
    ~Manager();

    /*!
     * @brief Executes the command if this staff can handle it
     * @param command The command to execute
     */
    void executeTask(Command *command) override;
};

#endif // MANAGER_H