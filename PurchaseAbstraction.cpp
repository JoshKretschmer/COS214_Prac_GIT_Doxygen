#include "PurchaseAbstraction.h"

PurchaseAbstraction::PurchaseAbstraction(PurchaseImplementor *impl) {

}

//###################################################

CustomerPurchase::CustomerPurchase() {

}

void CustomerPurchase::processPurchase(Order &order) {

}

bool CustomerPurchase::checkInventory(Plant &plant) {

}

void CustomerPurchase::coordinateStaff() {

}

bool CustomerPurchase::handlePayment(double amount) {

}

//###################################################

StaffPurchase::StaffPurchase() {

}

void StaffPurchase::processPurchase(Order &order) {

}

bool StaffPurchase::checkInventory(Plant &plant) {

}

void StaffPurchase::coordinateStaff() {

}

bool StaffPurchase::handlePayment(double amount) {

}




