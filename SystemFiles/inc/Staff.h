#ifndef STAFF_H
#define STAFF_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

class Command;
class Plant;
class Request;

/*!
 * @class Horticulturist
 *
 * @brief Parent class for Staff members
 */
class Staff
{
protected:
    std::string staffName;
    std::string staffID;
    std::string staffType;
    Staff *nextHandler;
    static int instanceCount;
    void forwardCommand(Command *_command);
    virtual void executeTask(Command *_command);

public:
    Staff(std::string _staffName);
    virtual ~Staff();
    void handleCommand(Command *command); // for chain of responsibility
    std::string getStaffName() { return staffName; };
    std::string getStaffID() { return staffID; };
    std::string getStaffType() { return staffType; };
    void setNextHandler(Staff *_handler);
    Staff *getNextHandler() const
    {
        return nextHandler;
    }
};

#endif // STAFF_H