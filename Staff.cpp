#include "Staff.h"
#include <iostream>

using namespace std;

Staff::Staff() {
    mediator = nullptr;
    nextHandler = nullptr;
}

Staff::~Staff() {

}

void Staff::handleRequest(Request &request) {
    cout << "Staff handling request..." << endl;
}

void Staff::update(Subject &subject) {
    Plant* plant = dynamic_cast<Plant*>(&subject);
    if (plant) {
        cout << "Staff notified of plant state: " << plant->getDetails() << endl;
    }
}

void Staff::setStrategy(StaffStrategy *strategy) {
    // Implement if you want to dynamically change staff care strategy
}

void Staff::executeAction(Command *command) {
    if (command) {
        command->execute();
    }
}

void Staff::communicateWithClerk(string message) {
    cout << "Staff communicates: " << message << endl;
}

void Staff::forwardRequest() {
    if (nextHandler) {
        cout << "Forwarding request to next handler..." << endl;
        // nextHandler->handleRequest(...); // Pass the request
    }
}

//########################################################

SalesAssociate::SalesAssociate() {

}

SalesAssociate::~SalesAssociate() {
    
}

void SalesAssociate::handleRequest(Request &request) {
    cout << "SalesAssociate handling customer request." << endl;
}

string SalesAssociate::answerQuestion(string question) {
    return "SalesAssociate answers: " + question;
}

//########################################################

Horticulturist::Horticulturist() {

}

Horticulturist::~Horticulturist() {

}

void Horticulturist::handleRequest(Request &request) {
    cout << "Horticulturist handling care request." << endl;
}

void Horticulturist::performCare(Plant &plant) {
    cout << "Horticulturist performing care for plant: " << plant.getDetails() << endl;

    // Use strategy pattern to perform care
    PlantCare* care = new CompositeCareStrategy();
    care->executeCare();
    delete care;

    // Optionally use Command pattern
    CareCommand cmd;
    cmd.execute();
}

//########################################################

Manager::Manager() {

}

Manager::~Manager() {

}

void Manager::handleRequest(Request &request) {
    cout << "Manager handling purchase request." << endl;
}

void Manager::purchaseStock(string plantType, int quantity) {
    cout << "Manager purchasing " << quantity << " of " << plantType << endl;
    // Integration with Inventory would go here
}

//########################################################

InventoryClerk::InventoryClerk() {
    inventory = nullptr;
}

InventoryClerk::~InventoryClerk() {

}

void InventoryClerk::handleRequest(Request &request) {
    cout << "InventoryClerk handling request." << endl;
}

void InventoryClerk::registerStaff(Staff *staff) {
    staffList.push_back(staff);
}

void InventoryClerk::notifyInventory(string updateType, Plant &plant) {
       cout << "InventoryClerk notified of " << updateType << " for plant " << plant.getDetails() << endl;
}

void InventoryClerk::routeUpdate(string message, Staff *sender, Inventory &inventory) {
    cout << "Routing update: " << message << endl;
    // Could notify multiple staff members or the mediator
}


