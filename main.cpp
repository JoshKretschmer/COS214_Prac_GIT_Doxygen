#include <iostream>
#include "Plant.h"
#include "Inventory.h"
#include "Customer.h"
#include "Order.h"
#include "NurseryMediator.h"

void chainTester(){
    NurseryMediator mediator;

    SalesAssociate sales("SA001", "Alice", nullptr, &mediator);
    Horticulturist horticulturist("HC001", "Bob", &sales, &mediator);
    Manager manager("MG001", "Charlie", &horticulturist, &mediator);
    InventoryClerk clerk("IC001", "Diana", &manager, &mediator);

    sales.setNextHandler(&horticulturist);
    horticulturist.setNextHandler(&manager);
    manager.setNextHandler(&clerk);

    Request salesRequest("Sales", "Customer inquiry about plant care.", "");
    Request careRequest("Care", "Need advice on plant health.", "");
    Request purchaseRequest("Purchase", "Order new stock of succulents.", "");
    Request generalRequest("General", "General inquiry.", "");

    sales.handleRequest(salesRequest);
    sales.handleRequest(careRequest);
    sales.handleRequest(purchaseRequest);
    sales.handleRequest(generalRequest);
}

#include "NurseryMediator.h"
#include "Staff.h"
#include "Inventory.h"
#include "Plant.h"
#include <iostream>
using namespace std;

void mediatorTester() {
    // Create the mediator
    NurseryMediator mediator;

    SalesAssociate sales("SA001", "Alice", nullptr, &mediator);
    Horticulturist horticulturist("HC001", "Bob", nullptr, &mediator);
    Manager manager("MG001", "Charlie", nullptr, &mediator);
    InventoryClerk clerk("IC001", "Diana", nullptr, &mediator);

    mediator.registerStaff(&sales);
    mediator.registerStaff(&horticulturist);
    mediator.registerStaff(&manager);
    mediator.registerStaff(&clerk);

    Inventory mainInventory(&mediator);
    Plant* plant1 = new PeanutCactus();
    Plant* plant2 = new HouseLeek();

    cout << "--- Adding plants to inventory ---" << endl;
    mainInventory.addPlant(plant1); 
    mainInventory.addPlant(plant2); 

    cout << "\n--- Moving a plant ---" << endl;
    mainInventory.movePlant(plant1, "NewState"); 

    cout << "\n--- Creating a PlantGroup ---" << endl;
    PlantGroup* succulentsGroup = new PlantGroup(&mediator);

    Inventory* cactusInventory = new Inventory(&mediator);
    cactusInventory->addPlant(new PeanutCactus());

    Inventory* leekInventory = new Inventory(&mediator);
    leekInventory->addPlant(new HouseLeek());

    succulentsGroup->add(cactusInventory);
    succulentsGroup->add(leekInventory);
    mainInventory.add(succulentsGroup);

    cout << "\n--- Inventory plants after adding PlantGroup ---" << endl;
    for (Plant* p : mainInventory.getPlants()) {
        cout << "Plant: " << p->getDetails() << endl;
    }

    cout << "\n--- Moving a plant inside PlantGroup ---" << endl;
    succulentsGroup->movePlant(plant1, "MovedState");
}

void iteratorTester() {
    cout << "--- Inventory Iterator Test ---" << endl;
    NurseryMediator mediator;

    Inventory inventory(&mediator);
    Plant* plant1 = new PeanutCactus();
    Plant* plant2 = new HouseLeek();

    inventory.addPlant(plant1);
    inventory.addPlant(plant2);
    inventory.addPlant(new PeanutCactus());
    inventory.addPlant(new HouseLeek());

    InventoryIterator* it = inventory.createIterator();

    cout << "--- Iterating over inventory ---" << endl;
    while (it->hasNext()) {
        Plant* p = it->next();
        if (p) cout << "Plant: " << p->getDetails() << endl;
    }

    delete it;
}

int main() {
    //chainTester();
    //mediatorTester();
    iteratorTester();
    return 0;
}
