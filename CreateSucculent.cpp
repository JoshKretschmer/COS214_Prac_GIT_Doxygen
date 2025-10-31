#include "CreateSucculent.h"
#include "PeanutCactus.h"
#include "HouseLeek.h"
#include <iostream>

/*!
 * @brief Creator function for Plant objects of type Succulent
 * Takes "HouseLeek" or "PeanutCactus" as input, or gives an error and returns nullptr
 *
 * @param name Specifies which plant object to create
 * @return Plant object of specified class, or nullptr as error
 */
Plant *CreateSucculent::createPlant(std::string name) {
    if (name == "PeanutCactus") {
        return new PeanutCactus();
    } else if (name == "HouseLeek") {
        return new HouseLeek();
    } else {
        std::cerr << "Invalid plant name " + name + ", please try again" << std::endl ;
        return nullptr;
    }
}