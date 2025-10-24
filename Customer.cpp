#include "Customer.h"

Customer::Customer() {

}

Customer::~Customer() {

}

Request *Customer::makeRequest(string type, string details) {
    return new Request(type, details, "Placeholder action");
}

void Customer::browsePlants(Inventory& inventory) {
    //this should have an iterator used here;
}

void Customer::startPurchase(Plant* plant) {
    //invoke the purchase command
}

void Customer::customizeOrder(string customization) {
    //this will utilize the plant decorator 
}

void Customer::undoCustomization() {
    //this will invoke the memento
}

void Customer::confirmPurchase() {
    //give output, delete from system, call for inventory.remove();
}

