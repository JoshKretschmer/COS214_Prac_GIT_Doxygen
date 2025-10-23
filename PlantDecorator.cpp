/*!
*  @file PlantDecorator.cpp
 *
 *  @brief Contains function definitions for the PlantDecorator functions defined in PlantDecorator.h
 */

#include "PlantDecorator.h"

//Plant (Component) is ConcretePlant (ConcreteComponent)

//#################################################

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


//#################################################

/*!
 * Return string gotten for wrappedPlant object, appended with "Decoration: Arrangement"
 *
 * @return Basic details of decorated plant
 */
string ArrangementDecorator::getDetails() {
    if (this->getWrapped() == nullptr) {
        return "Plant to be decorated has not been set";
    }

    string det = getWrapped()->getDetails();
    det += "Decoration: Arrangement \n";
    return det;
}

/*!
 * @brief Calculates the price as wrappedPlant->price + 10.00
 *
 * @return Full price of decorated plant
 */
double ArrangementDecorator::getCost() {
    if (this->getWrapped() == nullptr) {
        return 0;
    }

    double cost = getWrapped()->getCost();
    cost += 10;
    return cost;
}

//#################################################

/*!
 * Return string gotten for wrappedPlant object, appended with "Decoration: Pot"
 *
 * @return Basic details of decorated plant
 */
string PotDecorator::getDetails() {
    if (this->getWrapped() == nullptr) {
        return "Plant to be decorated has not been set";
    }

    string det = getWrapped()->getDetails();
    det += "Decoration: Pot \n";
    return det;
}

/*!
 * @brief Calculates the price as wrappedPlant->price + 20.00
 *
 * @return Full price of decorated plant
 */
double PotDecorator::getCost() {
    if (this->getWrapped() == nullptr) {
        return 0;
    }

    double cost = getWrapped()->getCost();
    cost += 20;
    return cost;
}

//#################################################

/*!
 * Return string gotten for wrappedPlant object, appended with "Decoration: Wrap"
 *
 * @return Basic details of decorated plant
 */
string WrapDecorator::getDetails() {
    if (this->getWrapped() == nullptr) {
        return "Plant to be decorated has not been set";
    }

    string det = getWrapped()->getDetails();
    det += "Decoration: Wrap \n";
    return det;
}

/*!
 * @brief Calculates the price as wrappedPlant->price + 15.00
 *
 * @return Full price of decorated plant
 */
double WrapDecorator::getCost() {
    if (this->getWrapped() == nullptr) {
        return 0;
    }

    double cost = getWrapped()->getCost();
    cost += 15;
    return cost;
}