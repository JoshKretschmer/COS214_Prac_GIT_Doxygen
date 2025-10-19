#include "Plant.h"
#include "PlantFactory.h"
#include <iostream>

//Ophelia Testing Main

int main() {
    //Factory Testing

    CreateFlower test1;
    CreateSucculent test2;
    CreateShrub test3;

    Plant* f1 = test1.createPlant("Orchid");
    Plant* f2 = test1.createPlant("Marigold");
    Plant* f3 = test1.createPlant("FakeFlower");

    Plant* Sc1 = test2.createPlant("PeanutCactus");
    Plant* Sc2 = test2.createPlant("HouseLeek");
    Plant* Sc3 = test2.createPlant("FakeCactus");

    Plant* Sh1 = test3.createPlant("BeeBlossom");
    Plant* Sh2 = test3.createPlant("HoneySuckle");
    Plant* Sh3 = test3.createPlant("FakeShrub");

    if (f3 == nullptr && Sc3 == nullptr && Sh3 == nullptr) {
        cout << "Error plant creation done correctly" << endl;
    }
    cout << f1->getDetails();
    cout << f2->getDetails();
    cout << Sc1->getDetails();
    cout << Sc2->getDetails();
    cout << Sh1->getDetails();
    cout << Sh2->getDetails();

    //####################################################################

    return 0;
}