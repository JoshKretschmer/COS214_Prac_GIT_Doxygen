#ifndef REQUEST_H
#define REQUEST_H

#include <string>
using namespace std;

class Request {
    private:
        string type;
        string details;
        string action;
    public:
        Request();
        Request(string type, string details, string action);
        ~Request();
        void setType(string type);
        void setAction(string action);
        void setDetails(string details);
        string getType();
        string getDetails();
        string getAction();
};

//how are we going to handle these, what types of requests can be made?

#endif //REQUEST_H