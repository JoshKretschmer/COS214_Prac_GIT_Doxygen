#ifndef REQUEST_H
#define REQUEST_H

#include "Staff.h"
#include "Plant.h"
#include "Customer.h"
#include <iostream>
#include <string>
#include <vector>

class Staff;
class Plant;

class Request {
    private:
        //the request is made, and it is used with the command to do what it does
        std::string plantID;
        std::string type;
        std::string plantType;
        std::string extra;
        Customer* sender;
        //types of commands: sales, inventory, manager, greenhouse
        Staff* receiver; //who is supposed to handle it
    public:
        Request(Customer* _sender, Staff* receiver) ;
        ~Request();
        void setPlantType(std::string _plantType);
        std::string getPlantType();
        void setPlantID(std::string _plantID);
        std::string getPlantID();
        void setType(std::string _type);
        std::string getType();
        void setSender(Customer* _sender);
        Customer* getSender();
        void setExtra(std::string _extra);
        std::string getExtra() ;
        void setReceiver(Staff* _receiver);
        Staff* getReceiver() ;
};


#endif //REQUEST_H