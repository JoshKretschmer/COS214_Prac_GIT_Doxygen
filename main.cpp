#include <iostream>
#include <cassert>
#include <string>

#include "CreateSucculent.h"
#include "CreateFlower.h"
#include "CreateShrub.h"

void TestFactory()
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

    std::cout << "\nAll tests completed successfully\n";
    std::cout << "Factory, Prototype, and State patterns are working\n";
}

int main()
{
    TestFactory();
    return 0;
}