#include "CreateFlower.h"
#include "Marigold.h"
#include "Orchid.h"
#include <iostream>

/*!
 * @brief Creator function for Plant objects of type Flower
 * Takes "Marigold" or "Orchid" as input, or gives an error and returns nullptr
 *
 * @param name Specifies which plant object to create
 * @return Plant object of specified class, or nullptr as error
 */
Plant *CreateFlower::createPlant(std::string name)
{
    if (name == "Marigold")
    {
        return new Marigold();
    }
    else if (name == "Orchid")
    {
        return new Orchid();
    }
    else
    {
        std::cerr << "Invalid plant name " + name + ", please try again" << std::endl;
        return nullptr;
    }
}