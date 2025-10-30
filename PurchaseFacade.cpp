#include "PurchaseFacade.h"
#include "PlantDecorator.h"

PurchaseFacade::PurchaseFacade(Inventory* inv/*, PaymentSystem* ps) : inventory(inv), paymentSystem(ps)*/) {}

PurchaseFacade::~PurchaseFacade() {}

// void PurchaseFacade::setPaymentSystem(PaymentSystem* ps) {
//     paymentSystem = ps;
// }

Order* PurchaseFacade::initiatePurchase(Customer* customer, Plant* plant) {
    Order* order = new Order();
    order->addPlant(plant);
    return order;
}

void PurchaseFacade::addCustomization(Order* order, string customization) {
    Plant* last = order->getLastPlant();
    if (last) {
        Plant* customized = customizePlant(last, customization);//untested
        order->replaceLastPlant(customized);
    }
}

 bool PurchaseFacade::processPayment(Order* order) {
//     if (paymentSystem) {
//         return paymentSystem->process(order->totalCost);
//     }
    return false;
 }

void PurchaseFacade::undoLastStep(Order* order) {
    order->undoLastAddition(); 
}

void PurchaseFacade::redoStep(Order* order) {
    order->redoLastStep(); 
}

void PurchaseFacade::completePurchase(Order* order) {
    if (processPayment(order)) {
        //remove plant from inventory
        vector<Plant*> plants = order->getPlants();
        for (auto p : plants) {
            inventory->removePlant(p->getID());
        }

        //clear Memento history to finalize
        vector<Memento*>& undos = order->getMementos();
        for (auto m : undos) delete m;
        undos.clear();
        vector<Memento*>& redos = order->getRedoMementos();
        for (auto m : redos) delete m;
        redos.clear();
        cout << "Purchase completed." << endl;
    } else {
        cout << "Payment failed." << endl;
    }
}

Plant* PurchaseFacade::customizePlant(Plant* plant, string decor) {
    //not implemented yet, uses decorator
    return NULL;
}