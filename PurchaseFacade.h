#ifndef PURCHASEFACADE_H
#define PURCHASEFACADE_H

#include "Inventory.h"
#include "Order.h"
#include "Customer.h"
#include "Plant.h"
#include "NurseryMediator.h"
#include "PurchaseAbstraction.h"
#include <string>
using namespace std;

class PaymentSystem {
    public:
        PaymentSystem();
        ~PaymentSystem();
        bool process(double amount);
};

class PurchaseFacade {
    private:
        Inventory* inventory;
        NurseryMediator* staffMediator;
        PaymentSystem* paymentSystem;
        //PurchaseAbstraction purchaseAbstraction;
    public:
        PurchaseFacade();
        ~PurchaseFacade();
        Order* initializePurchase(Customer& customer, Plant* plant);
        void addCustomization(Order& order, string customization);
        bool processPayment(Order& order);
        void undoLastStep(Order& order);
        void completePurchase(Order& order);
        void setPurchasePOV(string POCType);
        void processPurchase(Order& order);
};



#endif //PURCHASEFACADE_H
