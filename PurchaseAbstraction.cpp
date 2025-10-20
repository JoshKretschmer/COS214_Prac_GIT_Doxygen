#include "PurchaseAbstraction.h"

PurchaseAbstraction::PurchaseAbstraction(PurchaseImplementor *impl) {

}

//###################################################


void CustomerPurchase::processPurchase(Order &order) {

}

bool CustomerPurchase::checkInventory(Plant &plant) {
    return false;
}

void CustomerPurchase::coordinateStaff() {

}

bool CustomerPurchase::handlePayment(double amount) {
    return false;
}

//###################################################



void StaffPurchase::processPurchase(Order &order) {

}

bool StaffPurchase::checkInventory(Plant &plant) {
    return false;
}

void StaffPurchase::coordinateStaff() {

}

bool StaffPurchase::handlePayment(double amount) {
    return false;
}




