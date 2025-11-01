#include "../inc/PlantDecorator.h"
#include <iostream>

/*!
 * @brief Basic constructor function for PlantDecorator
 */
PlantDecorator::PlantDecorator()
{
    wrappedPlant = nullptr;
}

/*!
 * @brief Basic destructor function for PlantDecorator
 */
PlantDecorator::~PlantDecorator()
{
    delete wrappedPlant;
    wrappedPlant = nullptr;
}

/*!
 * @brief Basic setter function for wrappedPlant attribute
 *
 * @param wrappedPlant Plant object to be attached to the Decorator object
 */
void PlantDecorator::setWrapped(Plant *wrappedPlant)
{
    std::cout << "Calling PlantDecorator::setWrapped(wrappedPlant="
              << (wrappedPlant ? wrappedPlant->getDetails().c_str() : "null") << ")\n";
    this->wrappedPlant = wrappedPlant;
}