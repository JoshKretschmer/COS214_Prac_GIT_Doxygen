#ifndef REQUEST_H
#define REQUEST_H

#include "libraries.h"

class Request {
    private:
        string type;
        string details;
        string action;
    public:
        Request(string type, string details, string action);
        ~Request();
        void setType(string type);
        void setAction(string action);
        void setDetails(string details);
        string getType();
        string getDetails();
        string getAction();

        // execute().       The request is the command. Passing it on a chain until it is handled. Only 
        //                  The staff member who can execute the Request execute
        //                  So request will be a interface and you'll have different "Requests" that inherit from it.
        //                  


};

//how are we going to handle these, what types of requests can be made?

#endif //REQUEST_H