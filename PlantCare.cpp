#include "PlantCare.h"
#include <iostream>

/*!
 * @brief Basic Abstract class constructor
 */
PlantCare::PlantCare()
{
    std::cout << "Constructing PlantCare base\n";
}

/*!
 * @brief Basic Abstract destructor
 */
PlantCare::~PlantCare()
{
    std::cout << "Destroying PlantCare base\n";
}