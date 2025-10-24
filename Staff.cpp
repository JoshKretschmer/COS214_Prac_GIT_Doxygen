#include "Staff.h"

Staff::Staff(string _name)
{
    Staffname = _name;
    this->nextHandler = NULL;
}

Staff::~Staff()
{
    nextHandler = NULL;
    //Nothign to destruct as of yet
}

void Staff::forwardRequest(Request *request)
{
    if (nextHandler)
    {
        cout<<"\nForwarding request from "<<Staffname<<" to "<< nextHandler->getStaffName()<<endl;
        nextHandler->handleRequest(request);
    }
    else
    {
        cout<<"End of chain reached — no handler for request type: "
            <<request->getType()<<endl;
    }
}

void Staff::setNextHandler(Staff * _handler)
{
    nextHandler = _handler;
}

string Staff::getStaffName()
{
    return Staffname;
}