#include "PurchaseFacade.h"
#include "PlantDecorator.h"
#include "PotDecorator.h"
#include "WrapDecorator.h"
#include "ArrangementDecorator.h"
#include <iostream>

PurchaseFacade::PurchaseFacade(Inventory *inv, PaymentSystem *ps)
{
    std::cout << "Calling PurchaseFacade Constructor (inventory="
              << (inv ? "non-null" : "null")
              << ", paymentSystem=" << (ps ? "non-null" : "null") << ")\n";
    inventory = inv;
    paymentSystem = ps;
    std::cout << "PurchaseFacade Constructor initialized\n";
}

PurchaseFacade::~PurchaseFacade()
{
    std::cout << "Calling PurchaseFacade Deconstructor\n";
}

void PurchaseFacade::setPaymentSystem(PaymentSystem *ps)
{
    std::cout << "Calling PurchaseFacade::setPaymentSystem(ps="
              << (ps ? "non-null" : "null") << ")\n";
    paymentSystem = ps;
    std::cout << "PurchaseFacade::setPaymentSystem() set paymentSystem\n";
}

Order *PurchaseFacade::initiatePurchase(Customer *customer, Plant *plant)
{
    std::cout << "Calling PurchaseFacade::initiatePurchase(customer="
              << (customer ? customer->getName() : "null")
              << ", plant=" << (plant ? plant->getDetails() : "null") << ")\n";

    Order *order = new Order();
    order->addPlant(plant);

    std::cout << "PurchaseFacade::initiatePurchase() returning new Order\n";
    return order;
}

void PurchaseFacade::addCustomization(Order *order, std::string customization)
{
    std::cout << "Calling PurchaseFacade::addCustomization(order="
              << (order ? order->getDetails() : "null")
              << ", customization=\"" << customization << "\")\n";

    if (!order)
    {
        std::cout << "PurchaseFacade::addCustomization() - null order, nothing done\n";
        return;
    }

    Plant *last = order->getLastPlant();
    if (last)
    {
        Plant *clonedPlant = last->clone();
        if (clonedPlant)
        {
            Plant *customized = customizePlant(clonedPlant, customization);
            if (customized)
            {
                order->replaceLastPlant(customized);
                std::cout << "PurchaseFacade::addCustomization() applied customization: "
                          << customization << "\n";
            }
            else
            {
                std::cerr << "PurchaseFacade::addCustomization() - failed to customize plant\n";
                delete clonedPlant; // Clean up if customization fails
            }
        }
        else
        {
            std::cerr << "PurchaseFacade::addCustomization() - failed to clone plant\n";
        }
    }
    else
    {
        std::cout << "PurchaseFacade::addCustomization() - no last plant to customize\n";
    }

    std::cout << "PurchaseFacade::addCustomization() completed\n";
}

bool PurchaseFacade::processPayment(Order *order)
{
    std::cout << "Calling PurchaseFacade::processPayment(order="
              << (order ? order->getDetails() : "null") << ")\n";

    if (!order)
    {
        std::cout << "PurchaseFacade::processPayment() - null order, returning false\n";
        return false;
    }

    if (paymentSystem)
    {
        bool result = paymentSystem->process(order->getTotalCost());
        std::cout << "PurchaseFacade::processPayment() - paymentSystem processed, result="
                  << (result ? "true" : "false") << "\n";
        return result;
    }

    std::cout << "PurchaseFacade::processPayment() - no paymentSystem, returning false\n";
    return false;
}

void PurchaseFacade::undoLastStep(Order *order)
{
    std::cout << "Calling PurchaseFacade::undoLastStep(order="
              << (order ? order->getDetails() : "null") << ")\n";

    order->undoLastAddition();

    std::cout << "PurchaseFacade::undoLastStep() completed\n";
}

void PurchaseFacade::redoStep(Order *order)
{
    std::cout << "Calling PurchaseFacade::redoStep(order="
              << (order ? order->getDetails() : "null") << ")\n";

    order->redoLastStep();

    std::cout << "PurchaseFacade::redoStep() completed\n";
}

void PurchaseFacade::completePurchase(Order *order)
{
    std::cout << "Calling PurchaseFacade::completePurchase(order="
              << (order ? order->getDetails() : "null") << ")\n";

    if (processPayment(order))
    {
        vector<Plant *> plants = order->getPlants();
        std::cout << "PurchaseFacade::completePurchase() removing "
                  << plants.size() << " plants from inventory\n";
        for (auto p : plants)
        {
            inventory->removePlant(p->getID());
        }

        vector<Memento *> &undos = order->getMementos();
        std::cout << "PurchaseFacade::completePurchase() clearing "
                  << undos.size() << " undo mementos\n";
        for (auto m : undos)
            delete m;
        undos.clear();

        vector<Memento *> &redos = order->getRedoMementos();
        std::cout << "PurchaseFacade::completePurchase() clearing "
                  << redos.size() << " redo mementos\n";
        for (auto m : redos)
            delete m;
        redos.clear();

        std::cout << "Purchase completed.\n";
    }
    else
    {
        std::cout << "Payment failed.\n";
    }

    std::cout << "PurchaseFacade::completePurchase() completed\n";
}

Plant *PurchaseFacade::customizePlant(Plant *plant, std::string decor)
{
    std::cout << "Calling PurchaseFacade::customizePlant(plant="
              << (plant ? plant->getDetails() : "null")
              << ", decor=\"" << decor << "\")\n";

    if (!plant)
    {
        std::cout << "PurchaseFacade::customizePlant() - null plant, returning nullptr\n";
        return nullptr;
    }

    if (decor == "Arrange")
    {
        ArrangementDecorator *newD = new ArrangementDecorator();
        newD->setWrapped(plant);
        std::cout << "PurchaseFacade::customizePlant() returning ArrangementDecorator\n";
        return newD;
    }
    else if (decor == "Pot")
    {
        PotDecorator *newD = new PotDecorator();
        newD->setWrapped(plant);
        std::cout << "PurchaseFacade::customizePlant() returning PotDecorator\n";
        return newD;
    }
    else if (decor == "Wrap")
    {
        WrapDecorator *newD = new WrapDecorator();
        newD->setWrapped(plant);
        std::cout << "PurchaseFacade::customizePlant() returning WrapDecorator\n";
        return newD;
    }
    else
    {
        std::cerr << "Unknown decoration '" << decor << "'. Plant unchanged.\n";
        std::cout << "PurchaseFacade::customizePlant() returning original plant\n";
        return plant;
    }
}