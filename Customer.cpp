#include "Customer.h"

Customer::Customer() {

}

Customer::~Customer() {

}

Request *Customer::makeRequest(string type, string details) {
    return new Request(type, details, "Placeholder action");
}

void Customer::browsePlants(Inventory& inventory) {

}

void Customer::startPurchase(Plant* plant) {

}

void Customer::customizeOrder(string customization) {

}

void Customer::undoCustomization() {

}

void Customer::confirmPurchase() {

}

