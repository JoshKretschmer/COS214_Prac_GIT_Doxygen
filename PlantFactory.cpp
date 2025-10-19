#include "PlantFactory.h"

PlantFactory::PlantFactory() {

}

PlantFactory::~PlantFactory() {

}

//###############################################

//create a succulent depending on input string
Plant *CreateSucculent::createPlant(string name) {
    if (name == "PeanutCactus") {
        return new PeanutCactus();
    } else if (name == "HouseLeek") {
        return new HouseLeek();
    } else {
        std::cerr << "Invalid plant name " + name + ", please try again" << std::endl ;
        return nullptr;
    }
}

//###############################################

//create flower based on inpute string value
Plant *CreateFlower::createPlant(string name) {
    if (name == "Marigold") {
        return new Marigold();
    } else if (name == "Orchid") {
        return new Orchid();
    } else {
        std::cerr << "Invalid plant name " + name + ", please try again" << std::endl ;
        return nullptr;
    }
}

//###############################################

//create shrub based on input string value
Plant *CreateShrub::createPlant(string name) {
    if (name == "HoneySuckle") {
        return new HoneySuckle();
    } else if (name == "BeeBlossom") {
        return new BeeBlossom();
    } else {
        std::cerr << "Invalid plant name " + name + ", please try again" << std::endl ;
        return nullptr;
    }
}