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
        ~Request();
        string getType();
};



#endif //REQUEST_H
