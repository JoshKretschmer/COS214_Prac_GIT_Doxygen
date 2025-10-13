#ifndef PURCHASEIMPLEMENTOR_H
#define PURCHASEIMPLEMENTOR_H

#include "Plant.h"
#include "Inventory.h"

class PurchaseImplementor {
    public:
        PurchaseImplementor();
        ~PurchaseImplementor();
        bool doInventoryCheck(Plant& plant);
        void doStaffCoordination();
        bool doPayment(double amount);
};

class ConcretePurchaseImplementor : public PurchaseImplementor {
    private:
        Inventory* inventory;
        NurseryMediator* mediator;
    public:
        ConcretePurchaseImplementor();
        ~ConcretePurchaseImplementor();
        bool doInventoryCheck(Plant& plant);
        void doStaffCoordination();
        bool doPayment(double amount);
};



#endif //PURCHASEIMPLEMENTOR_H
