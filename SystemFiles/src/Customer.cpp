#include "../inc/Customer.h"
#include "../inc/SalesCommand.h"
#include "../inc/InventoryCommand.h"
#include "../inc/PlantDecorator.h"
#include "../inc/PotDecorator.h"
#include "../inc/WrapDecorator.h"
#include "../inc/ArrangementDecorator.h"
#include "../inc/Request.h"
#include "../inc/Order.h"
#include <iostream>

/*!
 * @brief Basic constructor for customer object
 */
Customer::Customer(std::string _name, std::string _id, Staff *_salesPerson)
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
    currentOrder = nullptr;
}

/*!
 * @brief Create a request with specified type, plantID, and extra information
 *
 * @param type Type of the request (e.g., "inventory", "sales")
 * @param plantID Unique ID of the plant
 * @param extra Additional information for the request
 * @return Newly created Request object
 */
Request *Customer::makeRequest(std::string type, std::string plantID, std::string extra)
{
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
    std::cout << "Calling Customer::browsePlants()\n";

    std::string plantID;
    std::cout << "Enter plant ID to browse (or 'quit'): ";
    std::cin >> plantID;

    if (plantID == "quit")
    {
        std::cout << "Customer::browsePlants() quitting\n";
        return;
    }

    Request *req = makeRequest("inventory", plantID, "");
    InventoryCommand cmd(req);
    salesPerson->handleCommand(&cmd);
    delete req;

    std::cout << "Customer::browsePlants() completed for plantID=\"" << plantID << "\"\n";
}

/*!
 * @brief Creates an Order object for the customer to make a purchase on
 */
void Customer::startPurchase()
{
    currentOrder = new Order();
}

/*!
 * @brief Add a plant to the customer's current order, optionally with decoration
 *
 * @param plantID Unique ID of the plant to add
 * @param decor Decoration type to apply (e.g., "Pot", "Wrap", "Arrange")
 */
void Customer::addPlant(std::string plantID, std::string decor)
{
    std::cout << "Calling Customer::addPlant(plantID=\"" << plantID
              << "\", decor=\"" << decor << "\")\n";

    InventoryClerk *clerk = dynamic_cast<InventoryClerk *>(salesPerson->getNextHandler());
    Plant *plant = nullptr;
    if (clerk)
    {
        plant = clerk->getPlant(plantID);
        std::cout << "Customer::addPlant() got plant: "
                  << (plant ? plant->getDetails() : "null") << "\n";
    }
    else
    {
        std::cout << "Customer::addPlant() - no valid clerk found\n";
    }

    if (!plant)
    {
        std::cerr << "Could not obtain plant " << plantID << " for the order.\n";
        std::cout << "Customer::addPlant() failed - no plant\n";
        return;
    }

    if (!decor.empty())
    {
        plant = customizeOrder(plant, decor);
        std::cout << "Customer::addPlant() applied decoration: \"" << decor << "\"\n";
    }

    currentOrder->addPlant(plant);
    std::cout << "Plant " << plantID << " added to your order.\n";

    std::cout << "Customer::addPlant() completed\n";
}

/*!
 * @brief Decorate a specified Plant object before adding it to an order
 *
 * @param plant Plant object to be decorated
 * @param decor Decoration to be added to the plant
 * @return Decorated Plant or basic Plant
 */
Plant *Customer::customizeOrder(Plant *plant, std::string decor)
{
    std::cout << "Calling Customer::customizeOrder(plant="
              << (plant ? plant->getDetails() : "null")
              << ", decor=\"" << decor << "\")\n";

    if (decor == "Arrange")
    {
        ArrangementDecorator *newD = new ArrangementDecorator();
        newD->setWrapped(plant);
        std::cout << "Customer::customizeOrder() returning ArrangementDecorator\n";
        return newD;
    }
    else if (decor == "Pot")
    {
        PotDecorator *newD = new PotDecorator();
        newD->setWrapped(plant);
        std::cout << "Customer::customizeOrder() returning PotDecorator\n";
        return newD;
    }
    else if (decor == "Wrap")
    {
        WrapDecorator *newD = new WrapDecorator();
        newD->setWrapped(plant);
        std::cout << "Customer::customizeOrder() returning WrapDecorator\n";
        return newD;
    }
    else
    {
        std::cerr << "Unknown decoration '" << decor << "'. Plant unchanged.\n";
        std::cout << "Customer::customizeOrder() returning original plant\n";
        return plant;
    }
}

/*!
 * @brief Undo the last action, i.e. remove the last plant added to the Order
 */
void Customer::undoAction()
{
    std::cout << "Calling Customer::undoAction()\n";

    if (currentOrder->isEmpty())
    {
        std::cout << "Nothing to undo.\n";
        std::cout << "Customer::undoAction() completed - order empty\n";
        return;
    }

    currentOrder->undoLastAddition();
    std::cout << "Last plant removed from the order.\n";
    std::cout << "Customer::undoAction() completed\n";
}

/*!
 * @brief Confirm the customer's current order and finalize the purchase
 */
void Customer::confirmPurchase()
{
    std::cout << "Calling Customer::confirmPurchase()\n";

    if (currentOrder->isEmpty())
    {
        std::cout << "Your order is empty – nothing to confirm.\n";
        std::cout << "Customer::confirmPurchase() completed - order empty\n";
        return;
    }

    std::cout << "\n=== FINAL ORDER ===\n";
    currentOrder->printOrder();
    std::cout << "====================\n";

    std::cout << "Purchase confirmed! Thank you, " << name << ".\n";

    delete currentOrder;
    startPurchase();

    std::cout << "Customer::confirmPurchase() completed\n";
}