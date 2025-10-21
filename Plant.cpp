#include "Plant.h"
#include <iostream>
using namespace std;

Plant::Plant() : currState(nullptr), careRegime(nullptr), health(100), price(0.0) {}

Plant::~Plant() {}

void Plant::changeState(PlantState* newState) {
    this->currState = newState;
    cout << "Plant state changed for " << getDetails() << endl;
    notify(); // Notify all observers (Staff)
}

bool Plant::needsCare() {
    // Placeholder logic
    return health < 80;
}

void Plant::add(InventoryComponent* comp) {
    // Not relevant for single plant
}

void Plant::remove(InventoryComponent* comp) {
    cout << getDetails() << " removed from inventory." << endl;
    notify(); // Notify staff observers
}

vector<Plant*> Plant::getPlants() {
    vector<Plant*> plants;
    plants.push_back(this);
    return plants;
}

void Plant::movePlant(Plant* plant, string newState) {
    cout << "Moving plant " << plant->getDetails() << " to " << newState << endl;
    notify();
}

//#####################################################

Succulent::Succulent() {}

//#####################################################

PeanutCactus::PeanutCactus() {
    price = 15.99;
}

string PeanutCactus::getDetails() {
    return "Peanut Cactus";
}

double PeanutCactus::getCost() {
    return price;
}

//#####################################################

HouseLeek::HouseLeek() {
    price = 12.49;
}

string HouseLeek::getDetails() {
    return "House Leek";
}

double HouseLeek::getCost() {
    return price;
}

//#####################################################

Flower::Flower() {}

//#####################################################

Orchid::Orchid() {
    price = 25.00;
}

string Orchid::getDetails() {
    return "Orchid";
}

double Orchid::getCost() {
    return price;
}

//#####################################################

Marigold::Marigold() {
    price = 9.99;
}

string Marigold::getDetails() {
    return "Marigold";
}

double Marigold::getCost() {
    return price;
}

//#####################################################

Shrub::Shrub() {}

//#####################################################

BeeBlossom::BeeBlossom() {
    price = 17.25;
}

string BeeBlossom::getDetails() {
    return "Bee Blossom";
}

double BeeBlossom::getCost() {
    return price;
}

//#####################################################

HoneySuckle::HoneySuckle() {
    price = 14.75;
}

string HoneySuckle::getDetails() {
    return "Honey Suckle";
}

double HoneySuckle::getCost() {
    return price;
}
