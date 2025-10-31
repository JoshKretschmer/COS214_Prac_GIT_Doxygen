#include "Customer.h"
#include "SalesCommand.h"
#include "InventoryCommand.h"
#include "PlantDecorator.h"
#include "PotDecorator.h"
#include "WrapDecorator.h"
#include "ArrangementDecorator.h"
#include "Request.h"
#include "Order.h"

#include <iostream>

/*!
 * @brief Basic constructor for customer object
 */
Customer::Customer(string _name, string _id, Staff *_salesPerson)
{
    salesPerson = _salesPerson;
    name = _name;
    id = _id;
    startPurchase();
}

/*!
 * @brief Basic destructor for customer object
 */
Customer::~Customer()
{
    delete currentOrder;
}

Request *Customer::makeRequest(string type, string plantID, string extra)
{
    // used to create request
    // need to be redone once request is set up
    Request *r = new Request(this, salesPerson);
    r->setType(type);
    r->setPlantID(plantID);
    r->setExtra(extra);
    return r;
}

/*!
 * @brief Create a request to get Information from Plants in Inventory
 */
void Customer::browsePlants()
{
    string plantID;
    cout << "Enter plant ID to browse (or 'quit'): ";
    cin >> plantID;
    if (plantID == "quit")
        return;

    Request *req = makeRequest("inventory", plantID, "");
    InventoryCommand cmd(req);
    salesPerson->handleCommand(&cmd);
    delete req;
}

/*!
 * @brief Creates an Order object for the customer to make a purchase on
 */
void Customer::startPurchase()
{
    currentOrder = new Order();
}

void Customer::addPlant(string plantID, string decor)
{
    Request *req = makeRequest("sales", plantID, decor);
    SalesCommand cmd(req);
    salesPerson->handleCommand(&cmd);

    InventoryClerk *clerk = dynamic_cast<InventoryClerk *>(salesPerson->getNextHandler());
    Plant *plant = nullptr;
    if (clerk)
    {
        plant = clerk->getPlant(plantID);
    }

    if (!plant)
    {
        cerr << "Could not obtain plant " << plantID << " for the order.\n";
        delete req;
        return;
    }

    if (!decor.empty())
    {
        plant = customizeOrder(plant, decor);
    }

    currentOrder->addPlant(plant);
    cout << "Plant " << plantID << " added to your order.\n";
    delete req;
}

/*!
 * @brief Decorate a specified Plant object before adding it to an order
 *
 * @param plant Plant object to be decorated
 * @param decor Decoration to be added to the plant
 * @return Decorated Plant or basic Plant
 */
Plant *Customer::customizeOrder(Plant *plant, string decor)
{

    if (decor == "Arrange")
    {
        ArrangementDecorator *newD = new ArrangementDecorator();
        newD->setWrapped(plant);
        return newD;
    }
    else if (decor == "Pot")
    {
        PotDecorator *newD = new PotDecorator();
        newD->setWrapped(plant);
        return newD;
    }
    else if (decor == "Wrap")
    {
        WrapDecorator *newD = new WrapDecorator();
        newD->setWrapped(plant);
        return newD;
    }
    else
    {
        cerr << "Unknown decoration '" << decor << "'. Plant unchanged.\n";
        return plant;
    }
}

/*!
 * @brief Undo the last action, i.e. remove the last plant added to the Order
 */
void Customer::undoAction()
{
    if (currentOrder->isEmpty())
    {
        cout << "Nothing to undo.\n";
        return;
    }
    currentOrder->undoLastAddition();
    cout << "Last plant removed from the order.\n";
}

void Customer::confirmPurchase()
{
    if (currentOrder->isEmpty())
    {
        cout << "Your order is empty – nothing to confirm.\n";
        return;
    }

    cout << "\n=== FINAL ORDER ===\n";
    currentOrder->printOrder();
    cout << "====================\n";

    cout << "Purchase confirmed! Thank you, " << name << ".\n";

    delete currentOrder;
    startPurchase();
}
