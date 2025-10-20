#include "Plant.h"

Plant::Plant() {

}

Plant::~Plant() {

}

void Plant::changeState(PlantState *newState) {

}

bool Plant::needsCare() {
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

}

//#####################################################

Succulent::Succulent() {

}

//#####################################################

PeanutCactus::PeanutCactus() {

}

string PeanutCactus::getDetails() {
    return "Peanut Cactus";
}

double PeanutCactus::getCost() {

}

//#####################################################

HouseLeek::HouseLeek() {

}

string HouseLeek::getDetails() {
    return "House Leek";
}

double HouseLeek::getCost() {
    return 0.0;
}

//#####################################################

Flower::Flower() {

}

//#####################################################

Orchid::Orchid() {

}

string Orchid::getDetails() {
    return "Orchid";
}

double Orchid::getCost() {
    return 0.0;
}

//#####################################################

Shrub::Shrub() {

}

//#####################################################

BeeBlossom::BeeBlossom() {

}

string BeeBlossom::getDetails() {
    return "Bee Blossom";
}

double BeeBlossom::getCost() {
    return 0.0;
}

//#####################################################

HoneySuckle::HoneySuckle() {

}

string HoneySuckle::getDetails() {
    return "Honey Suckle";
}

double HoneySuckle::getCost() {
    return 0.0;
}
