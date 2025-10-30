#include "PlantDecorator.h"

/*!
 * @brief Basic constructor function for PlantDecorator
 */
PlantDecorator::PlantDecorator() {
    wrappedPlant=nullptr;
}

/*!
 * @brief Basic destructor function for PlantDecorator
 */
PlantDecorator::~PlantDecorator() {
    delete wrappedPlant;
}

/*!
 * @brief Basic setter function for wrappedPlant attribute
 *
 * @param wrappedPlant Plant object to be attached to the Decorator object
 */
void PlantDecorator::setWrapped(Plant* wrappedPlant) {
    this->wrappedPlant = wrappedPlant;
}