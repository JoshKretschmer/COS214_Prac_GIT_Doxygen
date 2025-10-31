#include <iostream>
#include <cassert>
#include <string>
using namespace std;

#include "CreateSucculent.h"
#include "CreateFlower.h"
#include "CreateShrub.h"

int main()
{
    cout << "test factory\n\n";

    srand(42);

    cout << "Creating Succulents...\n";
    CreateSucculent succulentFactory;

    Plant *peanut = succulentFactory.createPlant("PeanutCactus");
    Plant *houseleek = succulentFactory.createPlant("HouseLeek");

    assert(peanut != nullptr);
    assert(houseleek != nullptr);

    cout << peanut->getDetails() << endl;
    cout << "Price: $" << peanut->getCost() << endl
         << endl;

    cout << houseleek->getDetails() << endl;
    cout << "Price: $" << houseleek->getCost() << endl
         << endl;

    assert(peanut->getCost() == 35.00);
    assert(houseleek->getCost() == 35.50);

    delete peanut;
    delete houseleek;

    cout << "Creating Flowers...\n";
    CreateFlower flowerFactory;

    Plant *orchid = flowerFactory.createPlant("Orchid");
    assert(orchid != nullptr);

    cout << orchid->getDetails() << endl;
    cout << "Price: $" << orchid->getCost() << endl
         << endl;

    assert(orchid->getCost() == 160.00);

    delete orchid;

    cout << "Creating Shrubs...\n";
    CreateShrub shrubFactory;

    Plant *honeysuckle = shrubFactory.createPlant("HoneySuckle");
    Plant *beeblossom = shrubFactory.createPlant("BeeBlossom");

    assert(honeysuckle != nullptr);
    assert(beeblossom != nullptr);

    cout << honeysuckle->getDetails() << endl;
    cout << beeblossom->getDetails() << endl;

    delete honeysuckle;
    delete beeblossom;

    cout << "Testing invalid plant name...\n";
    Plant *bad = succulentFactory.createPlant("InvalidPlant");

    if (bad == nullptr)
    {
        cout << "Correctly returned nullptr for invalid name.\n";
    }
    else
    {
        cout << "ERROR: Should have returned nullptr\n";
        delete bad;
    }

    cout << "\nAll tests completed successfully\n";
    cout << "factory pattern is working\n";

    return 0;
}