/*!
*  @file PlantFactory.cpp
 *
 * @brief Contains function definitions for the PlantFactory functions defined in PlantFactory.h
 */

#include "PlantFactory.h"

/*!
 * @brief Basic constructor for PlantFactory
 */
PlantFactory::PlantFactory() {

}

/*!
 * @brief Basic destructor for PlantFactory
 */
PlantFactory::~PlantFactory() {

}

//###############################################

/*!
 * @brief Creator function for Plant objects of type Succulent
 * Takes "HouseLeek" or "PeanutCactus" as input, or gives an error and returns nullptr
 *
 * @param name Specifies which plant object to create
 * @return Plant object of specified class, or nullptr as error
 */
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

/*!
 * @brief Creator function for Plant objects of type Flower
 * Takes "Marigold" or "Orchid" as input, or gives an error and returns nullptr
 *
 * @param name Specifies which plant object to create
 * @return Plant object of specified class, or nullptr as error
 */
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

/*!
 * @brief Creator function for Plant objects of type Shrub
 * Takes "HoneySuckle" or "BeeBlossom" as input, or gives an error and returns nullptr
 *
 * @param name Specifies which plant object to create
 * @return Plant object of specified class, or nullptr as error
 */
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