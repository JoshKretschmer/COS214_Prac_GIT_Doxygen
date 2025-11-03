#ifndef PURCHASEFACADE_H
#define PURCHASEFACADE_H

#include "Inventory.h"
#include "PaymentSystem.h"
#include "Order.h"
#include "Plant.h"
#include "Customer.h"

/*!
 * @class PurchaseFacade
 *
 * @brief system that the facade overviews, also forms the originator for the memonto class
 */

class PurchaseFacade
{
private:
    Inventory *inventory;
    PaymentSystem *paymentSystem;

    Plant *customizePlant(Plant *plant, std::string decor);

public:
    PurchaseFacade(Inventory *inv, PaymentSystem *ps);
    ~PurchaseFacade();

    void setPaymentSystem(PaymentSystem *ps);

    Order *initiatePurchase(Customer *customer, Plant *plant);

    void addCustomization(Order *order, std::string customization);

    bool processPayment(Order *order);

    void undoLastStep(Order *order);
    void redoStep(Order *order);
    void completePurchase(Order *order);

    void addPlantToOrder(Order *order, Plant *plant);
};

#endif // PURCHASEFACADE_H