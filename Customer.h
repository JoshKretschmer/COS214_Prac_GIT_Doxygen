#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Order.h"
#include "Request.h"
#include "Staff.h"
#include "Inventory.h"
using namespace std;

class Customer {
    private:
        string id;  //should make this static, so each customer instance has a unique id number. Unless in main, we have a list of set cusomter ID numbers we select from.
        string name;
        Order* currentOrder;
        InventoryClerk* clerk;
        SalesAssociate* salesPerson;
        
    public:
        Customer(string name,string id, InventoryClerk* _clerk, SalesAssociate* _salesPerson);  // this makes sense coz a customer should know who they talking to
        ~Customer();
        Request* makeRequest(string type, string details,string action);
        void browsePlants();
        void startPurchase();
        void customizeOrder();
        void undoCustomization();
        void confirmPurchase();
};



#endif //CUSTOMER_H