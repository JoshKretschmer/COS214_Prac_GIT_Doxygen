#include "CreateShrub.h"
#include "HoneySuckle.h"
#include "BeeBlossom.h"
#include <iostream>

/*!
 * @brief Creator function for Plant objects of type Shrub
 * Takes "HoneySuckle" or "BeeBlossom" as input, or gives an error and returns nullptr
 *
 * @param name Specifies which plant object to create
 * @return Plant object of specified class, or nullptr as error
 */
Plant *CreateShrub::createPlant(std::string name) {
    if (name == "HoneySuckle") {
        return new HoneySuckle();
    } else if (name == "BeeBlossom") {
        return new BeeBlossom();
    } else {
        std::cerr << "Invalid plant name " + name + ", please try again" << std::endl ;
        return nullptr;
    }
}