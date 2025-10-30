#ifndef STAFF_H
#define STAFF_H

#include "libraries.h"
#include "Request.h"
#include "Command.h"

class Command;

class Staff
{
protected:
    string staffName;
    string staffID;
    string staffType; //<------ initialized in derived classes
    Staff *nextHandler;
    static int instanceCount;
    void forwardCommand(Command* _command);  // <--- handled internally. Should not be able to forward a command on "request"
    virtual void executeTask(Command* _command)=0;

public:
    Staff(string _staffName);
    virtual ~Staff();
   void handleCommand(Command* command);       //<--- chain of responsibility
    string getStaffName(){return staffName;};
    string getStaffID(){return staffID;};
    string getStaffType(){return staffType;};
    void setNextHandler(Staff *_handler);


    // implement the passing of objects from Staff to Staff.
   // virtual void passToStaff(Staff* _staffMember, Plant* _plant)=0;

    // functions to auto task.
    // plant ids stored by horticulturist
};

#endif // STAFF_H