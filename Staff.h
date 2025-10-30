#ifndef STAFF_H
#define STAFF_H

#include "Request.h"
#include "Command.h"

class Command;

class Staff
{
protected:
    string staffName;
    string staffID;
    string staffType;
    Staff *nextHandler;
    static int instanceCount;
    void forwardCommand(Command* _command);
    void executeTask(Command* _command);

public:
    Staff(string _staffName);
    virtual ~Staff();
    void handleCommand(Command* command);       //<--- chain of responsibility
    string getStaffName(){return staffName;};
    string getStaffID(){return staffID;};
    string getStaffType(){return staffType;};
    void setNextHandler(Staff *_handler);
};

#endif //STAFF_H
