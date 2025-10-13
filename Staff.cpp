#include "Staff.h"

Staff::Staff() {

}

Staff::~Staff() {

}

void Staff::handleRequest(Request &request) {

}

void Staff::update(Subject &subject) {

}

void Staff::setStrategy(StaffStrategy *strategy) {

}

void Staff::executeAction(Command *command) {

}

void Staff::communicateWithClerk(string message) {

}

void Staff::forwardRequest() {

}

//########################################################

SalesAssociate::SalesAssociate() {

}

SalesAssociate::~SalesAssociate() {

}

void SalesAssociate::handleRequest(Request &request) {

}

string SalesAssociate::answerQuestion(string question) {

}

//########################################################

Horticulturist::Horticulturist() {

}

Horticulturist::~Horticulturist() {

}

void Horticulturist::handleRequest(Request &request) {

}

void Horticulturist::performCare(Plant &plant) {

}

//########################################################

Manager::Manager() {

}

Manager::~Manager() {

}

void Manager::handleRequest(Request &request) {

}

void Manager::purchaseStock(string plantType, int quantity) {

}

//########################################################

InventoryClerk::InventoryClerk() {

}

InventoryClerk::~InventoryClerk() {

}

void InventoryClerk::handleRequest(Request &request) {

}

void InventoryClerk::registerStaff(Staff *staff) {

}

void InventoryClerk::notifyInventory(string updateType, Plant &plant) {

}

void InventoryClerk::routeUpdate(string message, Staff *sender, Inventory &inventory) {

}


