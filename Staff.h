#ifndef STAFF_H
#define STAFF_H

#include "libraries.h"
#include "NurseryMediator.h"
#include "Plant.h"
#include "Inventory.h"
#include "Request.h"
#include "Observer.h"
#include "Command.h"

class StaffStrategy;
class NurseryMediator;
class InventoryClerk;
class Inventory;

class Staff : public Observer
{
    private:
        string id;
        string name;
        Staff* nextHandler;
        NurseryMediator* mediator;
    public:
        Staff();
        Staff(string id, string name, Staff* nextHandler, NurseryMediator* mediator);
        virtual ~Staff();
        virtual void handleRequest(Request& request) = 0;
        void update(Subject& subject);
        void setStrategy(StaffStrategy* strategy);
        void executeAction(Command* command);
        void communicateWithClerk(string message, InventoryClerk* clerk);
        void forwardRequest(Request& request);
        void setNextHandler(Staff* handler);
        string getName();
        string getId();
        void updatePlantNotification(string updateType, Plant& plant);
};

class SalesAssociate : public Staff {
    public:
        SalesAssociate();
        SalesAssociate(string id, string name, Staff* nextHandler, NurseryMediator* mediator);
        ~SalesAssociate();
        virtual void handleRequest(Request& request) override;
        string answerQuestion(string question);
};

class Horticulturist : public Staff {
    public:
        Horticulturist();
        Horticulturist(string id, string name, Staff* nextHandler, NurseryMediator* mediator);
        ~Horticulturist();
        virtual void handleRequest(Request& request) override;
        void performCare(Plant& plant);
};

class Manager : public Staff {
    public:
        Manager();
        Manager(string id, string name, Staff* nextHandler, NurseryMediator* mediator);
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
        InventoryClerk(string id, string name, Staff* nextHandler, NurseryMediator* mediator);
        ~InventoryClerk();
        void handleRequest(Request& request);
        void registerStaff(Staff* staff);
        void notifyInventory(string updateType, Plant& plant);
        void routeUpdate(string message, Staff* sender, Inventory& inventory);
        Inventory* getInventory();
        string getAvailablePlants();
};

#endif //STAFF_H