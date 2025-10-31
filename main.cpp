#include <iostream>
#include <cassert>
#include <string>

#include "CreateSucculent.h"
#include "CreateFlower.h"
#include "CreateShrub.h"
#include "Inventory.h"
#include "PlantGroup.h"
#include "Plant.h"
#include "PlantCare.h"
#include "PotDecorator.h"
#include "WrapDecorator.h"
#include "ArrangementDecorator.h"


void TestPlants()
{
    std::cout << "Test Factory\n\n";

    srand(42);

    std::cout << "Creating Succulents...\n";
    CreateSucculent succulentFactory;

    Plant *peanut = succulentFactory.createPlant("PeanutCactus");
    Plant *houseleek = succulentFactory.createPlant("HouseLeek");

    if (peanut == nullptr || houseleek == nullptr)
    {
        std::cout << "ERROR: Failed to create succulent\n";
    }
    else
    {
        std::cout << peanut->getDetails() << std::endl;
        std::cout << "Price: $" << peanut->getCost() << std::endl
                  << std::endl;

        std::cout << houseleek->getDetails() << std::endl;
        std::cout << "Price: $" << houseleek->getCost() << std::endl
                  << std::endl;

        if (peanut->getCost() != 35.00 || houseleek->getCost() != 35.50)
        {
            std::cout << "ERROR: Incorrect succulent prices\n";
        }
    }

    delete peanut;
    delete houseleek;

    std::cout << "Creating Flowers...\n";
    CreateFlower flowerFactory;

    Plant *orchid = flowerFactory.createPlant("Orchid");

    if (orchid == nullptr)
    {
        std::cout << "ERROR: Failed to create orchid\n";
    }
    else
    {
        std::cout << orchid->getDetails() << std::endl;
        std::cout << "Price: $" << orchid->getCost() << std::endl
                  << std::endl;

        if (orchid->getCost() != 160.00)
        {
            std::cout << "ERROR: Incorrect orchid price\n";
        }
    }

    delete orchid;

    std::cout << "Creating Shrubs...\n";
    CreateShrub shrubFactory;

    Plant *honeysuckle = shrubFactory.createPlant("HoneySuckle");
    Plant *beeblossom = shrubFactory.createPlant("BeeBlossom");

    if (honeysuckle == nullptr || beeblossom == nullptr)
    {
        std::cout << "ERROR: Failed to create shrub\n";
    }
    else
    {
        std::cout << honeysuckle->getDetails() << std::endl;
        std::cout << beeblossom->getDetails() << std::endl;

        if (honeysuckle->getCost() != 39.95 || beeblossom->getCost() != 21.00)
        {
            std::cout << "ERROR: Incorrect shrub prices\n";
        }
    }

    delete honeysuckle;
    delete beeblossom;

    std::cout << "Testing invalid plant name...\n";
    Plant *bad = succulentFactory.createPlant("InvalidPlant");

    if (bad == nullptr)
    {
        std::cout << "Correctly returned nullptr for invalid name.\n";
    }
    else
    {
        std::cout << "ERROR: Should have returned nullptr\n";
        delete bad;
    }

    std::cout << "\nCreating clone of PeanutCactus...\n";
    peanut = succulentFactory.createPlant("PeanutCactus");
    Plant *clone = peanut->clone();

    if (clone == nullptr)
    {
        std::cout << "ERROR: Clone failed\n";
    }
    else
    {
        std::cout << "Clone details:\n"
                  << clone->getDetails() << std::endl;
        std::cout << "Clone state: " << clone->getState() << std::endl;

        if (clone->getID() != peanut->getID() || clone->getCost() != peanut->getCost())
        {
            std::cout << "ERROR: Clone has different ID or price\n";
        }

        clone->incrementHealth(10);
        if (peanut->getState() == clone->getState())
        {
            std::cout << "ERROR: Clone and original share state\n";
        }
    }

    delete peanut;
    delete clone;

    std::cout << "\nTesting state transitions...\n";
    peanut = succulentFactory.createPlant("PeanutCactus");
    std::cout << "Initial state: " << peanut->getState() << std::endl;

    peanut->incrementHealth(3);
    std::cout << "After +3 health: " << peanut->getState() << std::endl;

    peanut->incrementHealth(5);
    std::cout << "After +5 health: " << peanut->getState() << std::endl;

    peanut->incrementHealth(10);
    std::cout << "After +10 health: " << peanut->getState() << std::endl;

    peanut->incrementHealth(-20);
    std::cout << "After -20 health: " << peanut->getState() << std::endl;

    delete peanut;

    std::cout << "\nTesting Strategy Pattern (careRegime)...\n";
    peanut = succulentFactory.createPlant("PeanutCactus");

    std::cout << "Plant ID: " << peanut->getID() << "\n";
    std::cout << "Care type: " << peanut->getCareRegime()->getCareType() << "\n";

    std::cout << "Applying full composite care:\n";
    peanut->getCareRegime()->executeCare();

    std::cout << "Health before care: " << peanut->getHealth() << "\n";
    peanut->incrementHealth(2); // Triggers careRegime + state
    std::cout << "Health after +2: " << peanut->getHealth() << "\n";
    std::cout << "State after care: " << peanut->getState() << "\n";

    delete peanut;

    std::cout << "Factory, Prototype, State, and Strategy patterns are working\n";
}

void TestComposite()
{
    std::cout << "Test Composite \n\n";

    Inventory inventory;

    CreateSucculent succulentFactory;
    CreateFlower flowerFactory;

    // create plants
    Plant *peanut = succulentFactory.createPlant("PeanutCactus");
    Plant *orchid = flowerFactory.createPlant("Orchid");

    // create groups
    PlantGroup *succulents = new PlantGroup("Succulents");
    PlantGroup *flowers = new PlantGroup("Flowers");

    // add plants to groups
    succulents->add(peanut);
    flowers->add(orchid);

    // add groups to inventory
    inventory.add(succulents);
    inventory.add(flowers);

    // test total plants
    std::vector<Plant *> allPlants = inventory.getPlants();
    std::cout << "Total plants: " << allPlants.size() << "\n";
    assert(allPlants.size() == 2);

    // remove a group
    inventory.remove(flowers);
    std::cout << "After removing Flowers group: " << inventory.getPlants().size() << "\n";
    assert(inventory.getPlants().size() == 1);

    std::cout << "Composite is working\n";
}

void TestIterator()
{
    std::cout << "Test Iterator \n\n";

    Inventory inventory;

    CreateSucculent succulentFactory;
    Plant *peanut = succulentFactory.createPlant("PeanutCactus");
    Plant *houseleek = succulentFactory.createPlant("HouseLeek");

    inventory.addPlant(peanut);
    inventory.addPlant(houseleek);

    // create group and add one more plant
    PlantGroup *succulents = new PlantGroup("Succulents");
    Plant *clone = peanut->clone();
    succulents->add(clone);
    inventory.add(succulents);

    // test the iterator
    std::cout << "Creating iterator...\n";
    InventoryIterator *it = inventory.createIterator();

    std::cout << "Iterating over all plants in inventory:\n";
    for (it->first(); it->hasNext(); it->next())
    {
        Plant *p = it->currentItem();
        if (p)
        {
            std::cout << "  -> " << p->getDetails()
                      << " | State: " << p->getState()
                      << " | Cost: $" << p->getCost() << "\n";
        }
    }

    delete it; 

    std::cout << "Iterator test complete. Total plants seen: "
              << inventory.getPlantCount() + 1 // +1 for the one in group
              << "\n\n";

    assert(inventory.getPlants().size() == 3);
    std::cout << "Iterator pattern is working\n";
}

void TestDecorator()
{
    std::cout << "Test Decorator \n\n";

    CreateSucculent factory;
    Plant* peanut = factory.createPlant("PeanutCactus");

    // decorate with pot then wrap then arrangement
    PotDecorator* pot = new PotDecorator();
    pot->setWrapped(peanut);

    WrapDecorator* wrap = new WrapDecorator();
    wrap->setWrapped(pot);

    ArrangementDecorator* arr = new ArrangementDecorator();
    arr->setWrapped(wrap);

    std::cout << "Final decorated plant:\n";
    std::cout << arr->getDetails();
    std::cout << "Total cost: $" << arr->getCost() << "\n";

    // clone test
    PlantDecorator* clone = arr->clone();
    std::cout << "Clone cost: $" << clone->getCost() << "\n";

    delete arr;
    delete clone;

    std::cout << "Decorator pattern is working\n";
}

int main()
{
    // TestPlants();
    // TestComposite();
    // TestIterator();
    TestDecorator();
    return 0;
}