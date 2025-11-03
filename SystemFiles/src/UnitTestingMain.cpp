#include <cassert>
#include <iostream>
#include <string>

#include "../inc/ArrangementDecorator.h"
#include "../inc/CreateFlower.h"
#include "../inc/CreateShrub.h"
#include "../inc/CreateSucculent.h"
#include "../inc/Customer.h"
#include "../inc/GreenHouseCommand.h"
#include "../inc/Horticulturist.h"
#include "../inc/Inventory.h"
#include "../inc/InventoryClerk.h"
#include "../inc/InventoryCommand.h"
#include "../inc/Manager.h"
#include "../inc/ManagerCommand.h"
#include "../inc/Memento.h"
#include "../inc/Order.h"
#include "../inc/PaymentSystem.h"
#include "../inc/Plant.h"
#include "../inc/PlantCare.h"
#include "../inc/PlantGroup.h"
#include "../inc/PotDecorator.h"
#include "../inc/PurchaseFacade.h"
#include "../inc/Request.h"
#include "../inc/SalesAssociate.h"
#include "../inc/SalesCommand.h"
#include "../inc/Staff.h"
#include "../inc/WrapDecorator.h"

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

TEST_CASE("Test Decorator") {
  CreateSucculent factory;

  SUBCASE("Single decoration cost calculation") {
    Plant *peanut = factory.createPlant("PeanutCactus");
    double baseCost = peanut->getCost();

    // testing pot decoration
    PotDecorator *pot = new PotDecorator();
    pot->setWrapped(peanut);
    REQUIRE(pot->getCost() == baseCost + 20.0);
    delete pot;

    // testing wrap decoration
    Plant *peanut2 = factory.createPlant("PeanutCactus");
    WrapDecorator *wrap = new WrapDecorator();
    wrap->setWrapped(peanut2);
    REQUIRE(wrap->getCost() == baseCost + 15.0);
    delete wrap;

    // testing arrangement decoration
    Plant *peanut3 = factory.createPlant("PeanutCactus");
    ArrangementDecorator *arr = new ArrangementDecorator();
    arr->setWrapped(peanut3);
    REQUIRE(arr->getCost() == baseCost + 10.0);
    delete arr;
  }

  SUBCASE("Multiple decorations stacking") {
    Plant *peanut = factory.createPlant("PeanutCactus");
    double baseCost = peanut->getCost();

    // all three decorations together
    PotDecorator *pot = new PotDecorator();
    pot->setWrapped(peanut);

    WrapDecorator *wrap = new WrapDecorator();
    wrap->setWrapped(pot);

    ArrangementDecorator *arr = new ArrangementDecorator();
    arr->setWrapped(wrap);

    // total cost: base + pot(20) + wrap(15) + arrangement(10)
    REQUIRE(arr->getCost() == baseCost + 20.0 + 15.0 + 10.0);

    delete arr; // clean up the entire chain
  }

  SUBCASE("Decorator details formatting") {
    Plant *peanut = factory.createPlant("PeanutCactus");

    PotDecorator *pot = new PotDecorator();
    pot->setWrapped(peanut);

    std::string details = pot->getDetails();
    REQUIRE(details.find("Decoration: Pot") != std::string::npos);
    REQUIRE(details.find("Peanut Cactus") != std::string::npos);

    delete pot;
  }

  SUBCASE("Decorator cloning preserves decorations") {
    Plant *peanut = factory.createPlant("PeanutCactus");

    // make decorated plant
    PotDecorator *pot = new PotDecorator();
    pot->setWrapped(peanut);

    WrapDecorator *wrap = new WrapDecorator();
    wrap->setWrapped(pot);

    // clone
    PlantDecorator *clone = wrap->clone();

    // clone has same cost and structure?
    REQUIRE(clone->getCost() == wrap->getCost());

    std::string originalDetails = wrap->getDetails();
    std::string cloneDetails = clone->getDetails();
    REQUIRE(originalDetails == cloneDetails);

    delete wrap;
    delete clone;
  }

  SUBCASE("Handling empty decorator") {
    // decorator without wrapped plant
    PotDecorator *emptyPot = new PotDecorator();
    REQUIRE(emptyPot->getCost() == 0.0);
    REQUIRE(emptyPot->getDetails() == "Plant to be decorated has not been set");
    delete emptyPot;
  }

  SUBCASE("Different plant types with same decorations") {
    // are decorations working consistently across different plant types
    Plant *peanut = factory.createPlant("PeanutCactus");
    Plant *houseleek = factory.createPlant("HouseLeek");

    double peanutCost = peanut->getCost();
    double houseleekCost = houseleek->getCost();

    // same decoration to different plants
    PotDecorator *pot1 = new PotDecorator();
    pot1->setWrapped(peanut);

    PotDecorator *pot2 = new PotDecorator();
    pot2->setWrapped(houseleek);

    REQUIRE(pot1->getCost() == peanutCost + 20.0);
    REQUIRE(pot2->getCost() == houseleekCost + 20.0);

    delete pot1;
    delete pot2;
  }
}

TEST_CASE("Test Command") {
  Inventory inventory;
  CreateSucculent factory;
  Plant *peanut = factory.createPlant("PeanutCactus");
  peanut->setID("PC001");
  inventory.addPlant(peanut);

  Staff salesPerson("SalesBob");
  Customer customer("Alice", "CUST001", &salesPerson);
  InventoryClerk clerk("Bob");
  Horticulturist horti("Charlie");
  Manager manager("Dave");

  clerk.setNextHandler(&horti);
  horti.setNextHandler(&manager);

  clerk.assignJob(&inventory);

  Request *req1 = new Request(&customer, &clerk);
  req1->setPlantID("PC001");
  req1->setType("inventory");
  InventoryCommand cmd1(req1);
  clerk.handleCommand(&cmd1);

  Request *req2 = new Request(&customer, &horti);
  req2->setPlantID("PC002");
  req2->setType("greenhouse");
  GreenHouseCommand cmd2(req2);
  clerk.handleCommand(&cmd2);

  Request *req3 = new Request(&customer, &manager);
  req3->setPlantID("PC003");
  req3->setType("manager");
  ManagerCommand cmd3(req3);
  clerk.handleCommand(&cmd3);

  delete req1;
  delete req2;
  delete req3;
}

TEST_CASE("Test Chain of Responsibility") {
  Inventory inventory;
  CreateSucculent factory;
  Plant *peanut = factory.createPlant("PeanutCactus");
  peanut->setID("PC001");
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

TEST_CASE("Test Memento") {
  Order order;

  CreateSucculent factory;
  Plant *peanut = factory.createPlant("PeanutCactus");
  Plant *houseleek = factory.createPlant("HouseLeek");

  order.addPlant(peanut);
  order.addPlant(houseleek);

  REQUIRE(order.getPlants().size() == 2);

  order.undoLastAddition();
  REQUIRE(order.getPlants().size() == 1);

  order.redoLastStep();
  REQUIRE(order.getPlants().size() == 2);

  order.undoLastAddition();
  order.undoLastAddition();
  REQUIRE(order.isEmpty());
}

TEST_CASE("Test Facade") {
  Inventory inventory;
  PaymentSystem paymentSystem;
  CreateSucculent factory;
  Plant *peanut = factory.createPlant("PeanutCactus");
  inventory.addPlant(peanut);
  SalesAssociate sales("Alice");
  Customer customer("Eve", "CUST001", &sales);

  PurchaseFacade facade(&inventory, &paymentSystem);

  Order *order =
      facade.initiatePurchase(&customer, factory.createPlant("PeanutCactus"));

  facade.addCustomization(order, "Pot");

  facade.undoLastStep(order);
  facade.redoStep(order);

  facade.completePurchase(order);

  delete order;
}
