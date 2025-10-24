#ifndef STAFF_H
#define STAFF_H

#include "libraries.h"
#include "Request.h"

class Staff
{
protected:
    string Staffname;
    Staff *nextHandler;

public:
    Staff(string name);
    virtual ~Staff();
    virtual void handleRequest(Request *request) = 0;
    virtual void peak() = 0;                 //to peak what the staff makes available to see
    void forwardRequest(Request *request);
    void setNextHandler(Staff *_handler);
    string getStaffName();

    // implement the passing of objects from Staff to Staff.
};

#endif // STAFF_H