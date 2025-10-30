#ifndef PURCHASEFACADE_H
#define PURCHASEFACADE_H

#include "Inventory.h" 
//#include "PaymentSystem.h" 
#include "Order.h"
#include "Plant.h"
#include "Customer.h" 

class PurchaseFacade
{
private:
    Inventory* inventory; 
    //PaymentSystem* paymentSystem; 

    Plant* customizePlant(Plant* plant, string decor); 

public:
    PurchaseFacade(Inventory* inv/*, PaymentSystem* ps*/);
    ~PurchaseFacade();

    //void setPaymentSystem(PaymentSystem* ps); 

    Order* initiatePurchase(Customer* customer, Plant* plant); 

    void addCustomization(Order* order, string customization); //uses decorator on last plant
    
    bool processPayment(Order* order);

    void undoLastStep(Order* order);
    void redoStep(Order* order);
    void completePurchase(Order* order);
};

#endif //PURCHASEFACADE_H