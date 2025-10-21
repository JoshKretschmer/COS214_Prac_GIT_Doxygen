#include "Plant.h"
#include "Inventory.h"
#include <iostream>
using namespace std;

Plant::Plant() {
    currState = nullptr;
    health = 100;
    careRegime = nullptr;
}

Plant::Plant(const Plant& other) {
    this->id = other.id;
    this->type = other.type;
    this->price = other.price;
    this->health = other.health;
    if (other.currState) {

        this->currState = other.currState; // Consider deep copy if needed
    } else {
        this->currState = nullptr;
    }
}

Plant::~Plant() {
    if (currState) {
        delete currState;
    }
    if (careRegime) {
        delete careRegime;
    }
}

void Plant::changeState(PlantState *newState) {
    if (currState) delete currState;
    currState = newState;
    cout << "Plant state changed to: " << currState->getStateName() << endl;
    notify(); //observer pattern notification
}

bool Plant::needsCare() {
    if (currState) {
        currState->handleCare(*this);
        return true;
    }
    return false;
}

void Plant::add(InventoryComponent *comp) {

}

void Plant::remove(InventoryComponent *comp) {

}

vector<Plant *> Plant::getPlants() {
    return vector<Plant*>();
}

void Plant::movePlant(Plant *plant, string newState) {
    // Simple implementation mapping string to states
    if (newState == "Seeding") plant->changeState(new SeedingState());
    else if (newState == "Growing") plant->changeState(new GrowingState());
    else if (newState == "Mature") plant->changeState(new MatureState());
    else if (newState == "Moult") plant->changeState(new MoultState());
}

//#####################################################

Succulent::Succulent() {

}

//#####################################################

PeanutCactus::PeanutCactus() {

}

Plant* PeanutCactus::clone() const {
    return new PeanutCactus(*this);  // copy constructor
}

string PeanutCactus::getDetails() {
    return "Peanut Cactus";
}

double PeanutCactus::getCost() {
    return 15.00;
}

//#####################################################

HouseLeek::HouseLeek() {

}

Plant* HouseLeek::clone() const {
    return new HouseLeek(*this);  // copy constructor
}
string HouseLeek::getDetails() {
    return "House Leek";
}

double HouseLeek::getCost() {
    return 10.00;
}

//#####################################################

Flower::Flower() {

}

//#####################################################

Orchid::Orchid() {

}

Plant* Orchid::clone() const {
    return new Orchid(*this);  // copy constructor
}

string Orchid::getDetails() {
    return "Orchid Flower";
}

double Orchid::getCost() {
    return 25.00;
}

//#####################################################

Shrub::Shrub() {

}



//#####################################################

BeeBlossom::BeeBlossom() {

}

Plant* BeeBlossom::clone() const {
    return new BeeBlossom(*this);  // copy constructor
}
string BeeBlossom::getDetails() {
    return "Bee Blossom Shrub";
}

double BeeBlossom::getCost() {
    return 20.00;
}

//#####################################################

HoneySuckle::HoneySuckle() {

}

Plant* HoneySuckle::clone() const {
    return new HoneySuckle(*this);  // copy constructor
}

string HoneySuckle::getDetails() {
    return "Honey Suckle Shrub";
}

double HoneySuckle::getCost() {
    return 18.00;
}
