#include "Plant.h"
#include "PlantFactory.h"
#include <iostream>
#include "PlantDecorator.h"

//Ophelia Testing Main

int main() {
    //Factory Testing

    CreateFlower test1;
    CreateSucculent test2;
    CreateShrub test3;

    Plant* f1 = test1.createPlant("Orchid");
    Plant* f2 = test1.createPlant("Marigold");
    //Plant* f3 = test1.createPlant("FakeFlower");

    Plant* Sc1 = test2.createPlant("PeanutCactus");
    Plant* Sc2 = test2.createPlant("HouseLeek");
    //Plant* Sc3 = test2.createPlant("FakeCactus");

    Plant* Sh1 = test3.createPlant("BeeBlossom");
    Plant* Sh2 = test3.createPlant("HoneySuckle");
    //Plant* Sh3 = test3.createPlant("FakeShrub");

    cout << f1->getDetails();
    cout << f2->getDetails();
    cout << Sc1->getDetails();
    cout << Sc2->getDetails();
    cout << Sh1->getDetails();
    cout << Sh2->getDetails();

    //####################################################################
    //State testing

    cout << "Killing the orchid: \n";
    cout << "Current state: " + f1->getState() + "\n";
    cout << "Current health: " + to_string(f1->getHealth()) + "\n";
    f1->setHealth(-1);

    cout << "\n\nGrowing marigold + moult state + die: \n";
    cout << "Current state: " + f2->getState() + "\n";
    cout << "Current health: " + to_string(f2->getHealth()) + "\n";
    f2->setHealth(2);
    cout << "Current state: " + f2->getState() + "\n";
    cout << "Current health: " + to_string(f2->getHealth()) + "\n";
    f2->setHealth(1);
    cout << "Current state: " + f2->getState() + "\n";
    cout << "Current health: " + to_string(f2->getHealth()) + "\n";
    f2->setHealth(3);
    cout << "Current state: " + f2->getState() + "\n";
    cout << "Current health: " + to_string(f2->getHealth()) + "\n";
    f2->setHealth(4);
    cout << "Current state: " + f2->getState() + "\n";
    cout << "Current health: " + to_string(f2->getHealth()) + "\n";
    f2->setHealth(2);
    cout << "Current state: " + f2->getState() + "\n";
    cout << "Current health: " + to_string(f2->getHealth()) + "\n";
    f2->setHealth(0);

    //####################################################################
    //PlantDecorator testing

    ArrangementDecorator d1;
    PotDecorator d2;
    WrapDecorator d3;

    d1.setWrapped(Sc1);
    d2.setWrapped(Sc2);
    d3.setWrapped(Sh1);

    cout << d1.getDetails() << endl;
    cout << d1.getCost() << endl;
    cout << d2.getDetails() << endl;
    cout << d2.getCost() << endl;
    cout << d3.getDetails() << endl;
    cout << d3.getCost() << endl;

    delete f1;
    delete f2;
    delete Sc1;
    delete Sc2;
    delete Sh1;
    delete Sh2;

    return 0;
}