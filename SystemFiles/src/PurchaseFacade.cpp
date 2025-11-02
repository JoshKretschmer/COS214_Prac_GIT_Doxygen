#include "../inc/PurchaseFacade.h"
#include "../inc/PlantDecorator.h"
#include "../inc/PotDecorator.h"
#include "../inc/WrapDecorator.h"
#include "../inc/ArrangementDecorator.h"
#include <iostream>

PurchaseFacade::PurchaseFacade(Inventory *inv, PaymentSystem *ps)
{
    inventory = inv;
    paymentSystem = ps;
}

PurchaseFacade::~PurchaseFacade()
{
}

void PurchaseFacade::setPaymentSystem(PaymentSystem *ps)
{
    paymentSystem = ps;
}

Order *PurchaseFacade::initiatePurchase(Customer *customer, Plant *plant)
{
    Order *order = new Order();
    order->addPlant(plant);

    return order;
}

void PurchaseFacade::addCustomization(Order *order, std::string customization)
{
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
    if (!order)
    {
        std::cout << "PurchaseFacade::processPayment() - null order, returning false\n";
        return false;
    }

    if (paymentSystem)
    {
        bool result = paymentSystem->process(order->getTotalCost());
        return result;
    }

    std::cout << "PurchaseFacade::processPayment() - no paymentSystem, returning false\n";
    return false;
}

void PurchaseFacade::undoLastStep(Order *order)
{
    order->undoLastAddition();
}

void PurchaseFacade::redoStep(Order *order)
{
    order->redoLastStep();

}

void PurchaseFacade::completePurchase(Order *order)
{
    if (processPayment(order))
    {
        vector<Plant *> plants = order->getPlants();
        for (auto p : plants)
        {
            inventory->removePlant(p->getID());
        }

        vector<Memento *> &undos = order->getMementos();
        for (auto m : undos)
            delete m;
        undos.clear();

        vector<Memento *> &redos = order->getRedoMementos();
        for (auto m : redos)
            delete m;
        redos.clear();

        std::cout << "Purchase completed.\n";
    }
    else
    {
        std::cout << "Payment failed.\n";
    }

}

Plant *PurchaseFacade::customizePlant(Plant *plant, std::string decor)
{
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

void PurchaseFacade::addPlantToOrder(Order* order, Plant* plant)
{

    if (!order || !plant)
    {
        std::cout << "PurchaseFacade::addPlantToOrder() - null order or plant, nothing done\n";
        return;
    }

    order->addPlant(plant);
    std::cout << "PurchaseFacade::addPlantToOrder() - added plant: " << plant->getDetails() << "\n";
}