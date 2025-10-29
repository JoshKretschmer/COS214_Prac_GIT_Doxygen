#ifndef CUSTOMER_H
#define CUSTOMER_H

/*!
 * @headerfile Customer.h
 */

#include <string>
#include "Order.h"
#include "Request.h"
#include "Staff.h"
#include "InventoryClerk.h"
using namespace std;

/*!
 * @class Customer
 *
 * @brief Class for objects that execute the purchasing and decoration process on plants
 *
 * Makes request to Staff object to execute processes
 */
class Customer {
    private:
        string id;  //should make this static, so each customer instance has a unique id number. Unless in main, we have a list of set cusomter ID numbers we select from.
        string name;
        Order* currentOrder;
        Staff* salesPerson;
        
    public:
        Customer(string name,string id, InventoryClerk* _clerk, Staff* _salesPerson);  // this makes sense coz a customer should know who they're talking to
        ~Customer();
        Request* makeRequest(string type, string details,string action);
        void browsePlants();
        void startPurchase();
        void customizeOrder();
        void undoCustomization();
        void confirmPurchase();
};



#endif //CUSTOMER_H