#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Order.h"
#include "Request.h"
#include "Inventory.h"
using namespace std;

class Customer {
    private:
        string id;
        Order* currentOrder;
    public:
        Customer();
        ~Customer();
        Request* makeRequest(string type, string details);
        void browsePlants(Inventory& inventory);
        void startPurchase(Plant* plant);
        void customizeOrder(string customization);
        void undoCustomization();
        void confirmPurchase();
};



#endif //CUSTOMER_H
