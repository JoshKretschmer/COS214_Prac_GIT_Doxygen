#include "PlantFactory.h"

PlantFactory::PlantFactory() {

}

//###############################################

CreateSucculent::CreateSucculent() {

}

Plant *CreateSucculent::createPlant() {
    return nullptr;
}

//###############################################

CreateFlower::CreateFlower() {

}

Plant *CreateFlower::createPlant() {
    return nullptr;
}

//###############################################

CreateShrub::CreateShrub() {

}

Plant *CreateShrub::createPlant() {
    return nullptr;
}