#include "PurchaseImplementor.h"

PurchaseImplementor::PurchaseImplementor() {

}

PurchaseImplementor::~PurchaseImplementor() {

}

bool PurchaseImplementor::doInventoryCheck(Plant &plant) {
    return false;
}

void PurchaseImplementor::doStaffCoordination() {

}

bool PurchaseImplementor::doPayment(double amount) {
    return false;
}

//###########################################################

ConcretePurchaseImplementor::ConcretePurchaseImplementor() {

}

ConcretePurchaseImplementor::~ConcretePurchaseImplementor() {

}

bool ConcretePurchaseImplementor::doInventoryCheck(Plant &plant) {
    return false;
}

void ConcretePurchaseImplementor::doStaffCoordination() {

}

bool ConcretePurchaseImplementor::doPayment(double amount) {
    return false;
}


