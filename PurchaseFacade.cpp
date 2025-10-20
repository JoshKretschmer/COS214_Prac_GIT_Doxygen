#include "PurchaseFacade.h"

PurchaseFacade::PurchaseFacade() {

}

PurchaseFacade::~PurchaseFacade() {

}

Order * PurchaseFacade::initializePurchase(Customer &customer, Plant *plant) {
    return new Order();
}

void PurchaseFacade::addCustomization(Order &order, string customization) {

}

bool PurchaseFacade::processPayment(Order &order) {
    return false;
}

void PurchaseFacade::undoLastStep(Order &order) {

}

void PurchaseFacade::completePurchase(Order &order) {

}

void PurchaseFacade::setPurchasePOV(string POCType) {

}

void PurchaseFacade::processPurchase(Order &order) {

}
