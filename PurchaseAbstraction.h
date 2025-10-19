#ifndef PURCHASEABSTRACTION_H
#define PURCHASEABSTRACTION_H

#include "PurchaseImplementor.h"
#include "Order.h"
#include "Plant.h"

class PurchaseAbstraction {
    private:
        PurchaseImplementor* implementor;
    public:
        PurchaseAbstraction(PurchaseImplementor* impl);
        virtual ~PurchaseAbstraction();
        virtual void processPurchase(Order& order)=0;
        virtual bool checkInventory(Plant& plant)=0;
        virtual void coordinateStaff()=0;
        virtual bool handlePayment(double amount)=0;
};

class CustomerPurchase : public PurchaseAbstraction {
    public:
        CustomerPurchase();
        void processPurchase(Order& order);
        bool checkInventory(Plant& plant);
        void coordinateStaff();
        bool handlePayment(double amount);
};

class StaffPurchase : public PurchaseAbstraction {
    public:
        StaffPurchase();
        void processPurchase(Order& order);
        bool checkInventory(Plant& plant);
        void coordinateStaff();
        bool handlePayment(double amount);
};



#endif //PURCHASEABSTRACTION_H
