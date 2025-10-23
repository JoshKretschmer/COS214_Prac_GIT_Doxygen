#include "Staff.h"
#include <iostream>
using namespace std;

// ########################################################

Staff::Staff() : nextHandler(nullptr), mediator(nullptr) {}

Staff::Staff(string id, string name, Staff *nextHandler, NurseryMediator *mediator)
{
    this->id = id;
    this->name = name;
    this->nextHandler = nextHandler;
    this->mediator = mediator;
}

Staff::~Staff() {}

void Staff::update(Subject &subject)
{
    cout << name << " received an update from subject." << endl;
}

void Staff::setStrategy(StaffStrategy *strategy) {}

void Staff::executeAction(Command *command)
{
    if (command)
        command->execute();
}

void Staff::communicateWithClerk(string message, InventoryClerk *clerk)
{
    if (mediator)
    {
        // The mediator handles routing to the clerk
        mediator->routeUpdate(message, this, clerk->getInventory());
    }
}

void Staff::forwardRequest(Request &request)
{
    if (nextHandler)
    {
        cout << "Forwarding request from " << name << " to " << nextHandler->getName() << endl;
        nextHandler->handleRequest(request);
    }
    else
        cout << "End of chain reached — no handler for request type: "
             << request.getType() << endl;
}

void Staff::setNextHandler(Staff *handler)
{
    this->nextHandler = handler;
}

string Staff::getName()
{
    return name;
}

string Staff::getId()
{
    return id;
}

void Staff::updatePlantNotification(string updateType, Plant &plant)
{
    cout << name << " notified of " << updateType
         << " for plant: " << plant.getDetails() << endl;
}

// ########################################################

SalesAssociate::SalesAssociate() {}

SalesAssociate::SalesAssociate(string id, string name, Staff *nextHandler, NurseryMediator *mediator)
    : Staff(id, name, nextHandler, mediator) {}

SalesAssociate::~SalesAssociate() {}

void SalesAssociate::handleRequest(Request &request)
{
    if (request.getType() == "Sales" || request.getType() == "General")
    {
        cout << "SalesAssociate handling request: " << request.getDetails() << endl;
    }
    else
    {
        forwardRequest(request);
    }
}

string SalesAssociate::answerQuestion(string question)
{
    return "Answering customer question: " + question;
}

// ########################################################

Horticulturist::Horticulturist() {}

Horticulturist::Horticulturist(string id, string name, Staff *nextHandler, NurseryMediator *mediator)
    : Staff(id, name, nextHandler, mediator) {}

Horticulturist::~Horticulturist() {}

void Horticulturist::handleRequest(Request &request)
{
    if (request.getType() == "Care" || request.getType() == "General")
    {
        cout << "Horticulturist performing care request: " << request.getDetails() << endl;
    }
    else
    {
        forwardRequest(request);
    }
}

void Horticulturist::performCare(Plant &plant)
{
    cout << "Performing plant care for plant: " << plant.getDetails() << endl;
}

// ########################################################

Manager::Manager() {}

Manager::Manager(string id, string name, Staff *nextHandler, NurseryMediator *mediator)
    : Staff(id, name, nextHandler, mediator) {}

Manager::~Manager() {}

void Manager::handleRequest(Request &request)
{
    if (request.getType() == "Purchase" || request.getType() == "General")
    {
        cout << "Manager handling purchase request: " << request.getDetails() << endl;
    }
    else
    {
        forwardRequest(request);
    }
}

void Manager::purchaseStock(string plantType, int quantity)
{
    cout << "Manager purchasing " << quantity << " units of " << plantType << endl;
}

// ########################################################

InventoryClerk::InventoryClerk() : inventory(nullptr)
{
    staffList = vector<Staff *>();
}

InventoryClerk::InventoryClerk(string id, string name, Staff *nextHandler, NurseryMediator *mediator)
    : Staff(id, name, nextHandler, mediator), inventory(nullptr) {}

InventoryClerk::~InventoryClerk() {}

void InventoryClerk::handleRequest(Request &request)
{
    if (request.getType() == "Inventory" || request.getType() == "General")
    {
        cout << "InventoryClerk handling inventory request: " << request.getDetails() << endl;
    }
    else
    {
        forwardRequest(request);
    }
}

void InventoryClerk::registerStaff(Staff *staff)
{
    if (staff)
        staffList.push_back(staff);
}

void InventoryClerk::notifyInventory(string updateType, Plant &plant)
{
    if (inventory)
    {
        cout << "InventoryClerk updating inventory: " << updateType
             << " for plant " << plant.getDetails() << endl;
    }
}

void InventoryClerk::routeUpdate(string message, Staff *sender, Inventory &inventory)
{
    cout << "InventoryClerk received routed message from " << sender->getName()
         << ": " << message << endl;
    if (this->inventory)
    {
        cout << "InventoryClerk can update its internal inventory based on message." << endl;
    }
}

Inventory *InventoryClerk::getInventory()
{
    return inventory;
}

string InventoryClerk::getAvailablePlants()
{
    string _peanutCactus = _peanutCactus + "PeanutCactus: " + to_string(inventory->getStockLevel("PeanutCactus")) + "\n";
    string _houseLeek = _houseLeek + "HouseLeek: " + to_string(inventory->getStockLevel("HouseLeek")) + "\n";

    string _orchid = _orchid + "Orchid: " + to_string(inventory->getStockLevel("Orchid")) + "\n";
    string _maryGold = _maryGold + "MaryGold: " + to_string(inventory->getStockLevel("MaryGold")) + "\n";

    string _beeBlossom = _beeBlossom + "BeeBlossom: " + to_string(inventory->getStockLevel("BeeBlossom")) + "\n";
    string _honeySuckle = _honeySuckle + "HoneySuckle" + to_string(inventory->getStockLevel("HoneySuckle")) + "\n";

    string availablePlants = "";
    availablePlants += "\n\t...Succulent...\n";
    availablePlants += _peanutCactus + _houseLeek;
    availablePlants += "\n\t...Flower...\n";
    availablePlants += _orchid + _maryGold;
    availablePlants += "\n\t...Shrub...\n";
    availablePlants += _beeBlossom + _honeySuckle;
    
    return availablePlants;
}