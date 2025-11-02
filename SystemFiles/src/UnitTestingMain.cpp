#include <iostream>
#include <cassert>
#include <string>

#include "../inc/CreateSucculent.h"
#include "../inc/CreateFlower.h"
#include "../inc/CreateShrub.h"
#include "../inc/Inventory.h"
#include "../inc/PlantGroup.h"
#include "../inc/Plant.h"
#include "../inc/PlantCare.h"
#include "../inc/PotDecorator.h"
#include "../inc/WrapDecorator.h"
#include "../inc/ArrangementDecorator.h"
#include "../inc/Request.h"
#include "../inc/Customer.h"
#include "../inc/Staff.h"
#include "../inc/InventoryClerk.h"
#include "../inc/Horticulturist.h"
#include "../inc/Manager.h"
#include "../inc/InventoryCommand.h"
#include "../inc/GreenHouseCommand.h"
#include "../inc/ManagerCommand.h"
#include "../inc/SalesCommand.h"
#include "../inc/SalesAssociate.h"
#include "../inc/Order.h"
#include "../inc/PaymentSystem.h"
#include "../inc/PurchaseFacade.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../inc/doctest.h"

TEST_CASE("Test Plants") {
    srand(42);

    SUBCASE("Creating Succulents") {
        CreateSucculent succulentFactory;

        Plant *peanut = succulentFactory.createPlant("PeanutCactus");
        Plant *houseleek = succulentFactory.createPlant("HouseLeek");

        REQUIRE(peanut != nullptr);
        REQUIRE(houseleek != nullptr);

        REQUIRE(peanut->getCost() == 35.00);
        REQUIRE(houseleek->getCost() == 35.50);

        delete peanut;
        delete houseleek;
    }

    SUBCASE("Creating Flowers") {
        CreateFlower flowerFactory;

        Plant *orchid = flowerFactory.createPlant("Orchid");

        REQUIRE(orchid != nullptr);
        REQUIRE(orchid->getCost() == 160.00);

        delete orchid;
    }

    SUBCASE("Creating Shrubs") {
        CreateShrub shrubFactory;

        Plant *honeysuckle = shrubFactory.createPlant("HoneySuckle");
        Plant *beeblossom = shrubFactory.createPlant("BeeBlossom");

        REQUIRE(honeysuckle != nullptr);
        REQUIRE(beeblossom != nullptr);

        REQUIRE(honeysuckle->getCost() == 39.95);
        REQUIRE(beeblossom->getCost() == 21.00);

        delete honeysuckle;
        delete beeblossom;
    }

    SUBCASE("Testing invalid plant name") {
        CreateSucculent succulentFactory;
        Plant *bad = succulentFactory.createPlant("InvalidPlant");

        REQUIRE(bad == nullptr);
    }

    SUBCASE("Creating clone of PeanutCactus") {
        CreateSucculent succulentFactory;
        Plant *peanut = succulentFactory.createPlant("PeanutCactus");
        Plant *clone = peanut->clone();

        REQUIRE(clone != nullptr);
        REQUIRE(clone->getID() == peanut->getID());
        REQUIRE(clone->getCost() == peanut->getCost());

        clone->incrementHealth(10);
        REQUIRE(peanut->getState() != clone->getState());

        delete peanut;
        delete clone;
    }

    SUBCASE("Testing state transitions") {
        CreateSucculent succulentFactory;
        Plant *peanut = succulentFactory.createPlant("PeanutCactus");

        peanut->incrementHealth(3);
        peanut->incrementHealth(5);
        peanut->incrementHealth(10);
        peanut->incrementHealth(-20);

        delete peanut;
    }

    SUBCASE("Testing Strategy Pattern (careRegime)") {
        CreateSucculent succulentFactory;
        Plant *peanut = succulentFactory.createPlant("PeanutCactus");

        peanut->getCareRegime()->executeCare();

        int healthBefore = peanut->getHealth();
        peanut->incrementHealth(2);
        REQUIRE(peanut->getHealth() > healthBefore);

        delete peanut;
    }
}

TEST_CASE("Test Composite") {
    Inventory inventory;

    CreateSucculent succulentFactory;
    CreateFlower flowerFactory;

    Plant *peanut = succulentFactory.createPlant("PeanutCactus");
    Plant *orchid = flowerFactory.createPlant("Orchid");

    PlantGroup *succulents = new PlantGroup("Succulents");
    PlantGroup *flowers = new PlantGroup("Flowers");

    succulents->add(peanut);
    flowers->add(orchid);

    inventory.add(succulents);
    inventory.add(flowers);

    std::vector<Plant *> allPlants = inventory.getPlants();
    REQUIRE(allPlants.size() == 2);

    inventory.remove(flowers);
    REQUIRE(inventory.getPlants().size() == 1);
}

TEST_CASE("Test Iterator") {
    Inventory inventory;

    CreateSucculent succulentFactory;
    Plant *peanut = succulentFactory.createPlant("PeanutCactus");
    Plant *houseleek = succulentFactory.createPlant("HouseLeek");

    inventory.addPlant(peanut);
    inventory.addPlant(houseleek);

    PlantGroup *succulents = new PlantGroup("Succulents");
    Plant *clone = peanut->clone();
    succulents->add(clone);
    inventory.add(succulents);

    InventoryIterator *it = inventory.createIterator();

    int count = 0;
    for (it->first(); it->hasNext(); it->next()) {
        Plant *p = it->currentItem();
        REQUIRE(p != nullptr);
        count++;
    }

    REQUIRE(count == 3);

    delete it;
}

// Decorator Test
TEST_CASE("Test Decorator") {
    CreateSucculent factory;
    Plant *peanut = factory.createPlant("PeanutCactus");

    PotDecorator *pot = new PotDecorator();
    pot->setWrapped(peanut);

    WrapDecorator *wrap = new WrapDecorator();
    wrap->setWrapped(pot);

    ArrangementDecorator *arr = new ArrangementDecorator();
    arr->setWrapped(wrap);

    REQUIRE(arr->getCost() == 80.0);

    PlantDecorator *clone = arr->clone();

    delete arr;
    delete clone;
}


// Command Test

TEST_CASE("Test Chain of Responsibility") {
    Inventory inventory;
    CreateSucculent factory;
    Plant *peanut = factory.createPlant("PeanutCactus");
    inventory.addPlant(peanut);

    SalesAssociate sales("Alice");
    InventoryClerk clerk("Bob");
    Horticulturist horti("Charlie");
    Manager manager("Dave");
    sales.setNextHandler(&clerk);
    clerk.setNextHandler(&horti);
    horti.setNextHandler(&manager);

    clerk.assignJob(&inventory);

    Customer customer("Eve", "CUST001", &sales);

    Request *req1 = customer.makeRequest("sales", "PC001", "Pot");
    SalesCommand cmd1(req1);
    sales.handleCommand(&cmd1);
    delete req1;

    Request *req2 = customer.makeRequest("inventory", "PC001", "");
    InventoryCommand cmd2(req2);
    sales.handleCommand(&cmd2);
    delete req2;

    Request *req3 = customer.makeRequest("greenhouse", "PC001", "");
    GreenHouseCommand cmd3(req3);
    sales.handleCommand(&cmd3);
    delete req3;

    Request *req4 = customer.makeRequest("manager", "PC001", "");
    ManagerCommand cmd4(req4);
    sales.handleCommand(&cmd4);
    delete req4;
}

// Memento Test

// Facade Test

TEST_CASE("Test Facade") {
    Inventory inventory;
    PaymentSystem paymentSystem;
    CreateSucculent factory;
    Plant *peanut = factory.createPlant("PeanutCactus");
    inventory.addPlant(peanut);
    SalesAssociate sales("Alice");
    Customer customer("Eve", "CUST001", &sales);

    PurchaseFacade facade(&inventory, &paymentSystem);

    Order *order = facade.initiatePurchase(&customer, factory.createPlant("PeanutCactus"));

    facade.addCustomization(order, "Pot");

    facade.undoLastStep(order);
    facade.redoStep(order);

    facade.completePurchase(order);

    delete order;
}
