#include "Plant.h"
#include "PlantFactory.h"
#include "PlantState.h"
#include <iostream>
#include "PlantDecorator.h"
#include "doctest.h"

//Unit Tests

TEST_CASE("Plant Factory Testing") {
    SUBCASE("CreateSucculent") {
        CreateSucculent cs;
        Plant* peanut = cs.createPlant("PeanutCactus");
        Plant* house = cs.createPlant("HouseLeek");
        Plant* succFail = cs.createPlant("SuccFail");

        CHECK(peanut->getID().substr(0, 2) == "PC");
        CHECK(house->getID().substr(0, 2) == "HL");
        CHECK(succFail == nullptr);

        delete peanut;
        delete house;
        delete succFail;
    }
    SUBCASE("CreateFlower") {
        CreateFlower f;
        Plant* orchid = f.createPlant("Orchid");
        Plant* mari = f.createPlant("Marigold");
        Plant* flower = f.createPlant("Ghost");

        CHECK(orchid->getID().substr(0, 2) == "OR");
        CHECK(mari->getID().substr(0, 2) == "MG");
        CHECK(flower == nullptr);

        delete orchid;
        delete mari;
        delete flower;
    }
    SUBCASE("CreateShrub") {
        CreateShrub s;
        Plant* bee = s.createPlant("BeeBlossom");
        Plant* honey = s.createPlant("HoneySuckle");
        Plant* bush = s.createPlant("George");

        CHECK(bee->getID().substr(0, 2) == "BB");
        CHECK(honey->getID().substr(0, 2) == "HS");
        CHECK(bush == nullptr);

        delete bee;
        delete honey;
        delete bush;
    }
}

TEST_CASE("Plant Testing") {
    SUBCASE("Succulent Constructor") {
        Plant* testSc = new PeanutCactus();

        CHECK(testSc->getCost() == 35.00);
        CHECK(testSc->getType() == "Succulent");
        CHECK(testSc->getHealth() == 0);
        CHECK(testSc->getState() == "Seeding");

        delete testSc;
    }
    SUBCASE("Flower Constructor") {
        Plant* testF = new Orchid();

        CHECK(testF->getCost() == 160.00);
        CHECK(testF->getType() == "Flower");
        CHECK(testF->getHealth() == 0);
        CHECK(testF->getState() == "Seeding");
    }
    SUBCASE("Shrub Constructor") {
        Plant* testS = new BeeBlossom();

        CHECK(testS->getCost() == 21.00);
        CHECK(testS->getType() == "Shrub");
        CHECK(testS->getHealth() == 0);
        CHECK(testS->getState() == "Seeding");
    }

    SUBCASE("State Change + Care Check") {
        Plant* testS = new PeanutCactus();

        CHECK(testS->getState() == "Seeding");
        CHECK(testS->needsCare() == true);

        PlantState* mState = new MatureState();
        testS->changeState(mState);
        CHECK(testS->getState() == "Matured");
        CHECK(testS->needsCare() == false);

        delete testS;
    }
}

TEST_CASE("Plant Decorator Testing") {
    PeanutCactus petPlant;
    double pCost = petPlant.getCost();

    SUBCASE("Arrangement Test") {
        ArrangementDecorator testA;

        CHECK(testA.getCost() == 0);

        testA.setWrapped(&petPlant);

        CHECK(testA.getCost() == pCost+10);
    }
    SUBCASE("Pot Test") {
        PotDecorator testP;

        CHECK(testP.getCost() == 0);

        testP.setWrapped(&petPlant);

        CHECK(testP.getCost() == pCost+20);
    }
    SUBCASE("House Test") {
        WrapDecorator testW;

        CHECK(testW.getCost() == 0);

        testW.setWrapped(&petPlant);

        CHECK(testW.getCost() == pCost+15);
    }

}

TEST_CASE("Plant State Testing") {
    PeanutCactus petPlant;

    CHECK(petPlant.getState() == "Seeding");

    petPlant.incrementHealth(2);

    //health >=2
    CHECK(petPlant.getState() == "Growing");

    petPlant.incrementHealth(2);

    //health >=4
    CHECK(petPlant.getState() == "Matured");

    petPlant.incrementHealth(-2);

    //health <=2
    CHECK(petPlant.getState() == "Moulting");

    petPlant.incrementHealth(-2);

    //health <=0
    CHECK(petPlant.getState() == "Dead");
}

int main() {
/*

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
*/

    return 0;
}