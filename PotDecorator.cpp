#include "PotDecorator.h"

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

/*!
 *
 * @return Concrete clone of Decorator object
 */
PlantDecorator *PotDecorator::clone() {
    Plant* newP = this->getWrapped()->clone();

    PotDecorator* newD = new PotDecorator();
    newD->setWrapped(newP);

    return newD;
}