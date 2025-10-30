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
        string id;
        string name;
        Order* currentOrder;
        Staff* salesPerson;
        
    public:
        Customer(string name,string id, Staff* _salesPerson);
        ~Customer();
        Request* makeRequest(string type, string details,string action);
        void browsePlants();
        void startPurchase();
        void addPlant(string plantID, string decor);
        Plant* customizeOrder(Plant* plant, string decor);
        void undoAction();
        void confirmPurchase();
};



#endif //CUSTOMER_H