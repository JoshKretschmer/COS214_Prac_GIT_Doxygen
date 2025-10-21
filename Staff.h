#ifndef STAFF_H
#define STAFF_H

#include "NurseryMediator.h"
#include "Plant.h"
#include "Inventory.h"
#include "Request.h"
#include "Observer.h"
#include "Command.h"
#include <string>
#include <vector>
using namespace std;

class StaffStrategy;

class Staff : public Observer{
    private:
        string id;
        string name;
        Staff* nextHandler;
        NurseryMediator* mediator;
    public:
        Staff();
        virtual ~Staff();
        void handleRequest(Request& request);
        void update(Subject& subject);
        void setStrategy(StaffStrategy* strategy);
        void executeAction(Command* command);
        void communicateWithClerk(string message);
        void forwardRequest();
};

class SalesAssociate : public Staff {
    public:
        SalesAssociate();
        ~SalesAssociate();
        void handleRequest(Request& request);
        string answerQuestion(string question);
};

class Horticulturist : public Staff {
    public:
        Horticulturist();
        ~Horticulturist();
        void handleRequest(Request& request);
        void performCare(Plant& plant);
};

class Manager : public Staff {
    public:
        Manager();
        ~Manager();
        void handleRequest(Request& request);
        void purchaseStock(string plantType, int quantity);
};

class InventoryClerk : public Staff {
    private:
        vector<Staff*> staffList;
        Inventory* inventory;
    public:
        InventoryClerk();
        ~InventoryClerk();
        void handleRequest(Request& request);
        void registerStaff(Staff* staff);
        void notifyInventory(string updateType, Plant& plant);
        void routeUpdate(string message, Staff* sender, Inventory& inventory);
};

#endif //STAFF_H
