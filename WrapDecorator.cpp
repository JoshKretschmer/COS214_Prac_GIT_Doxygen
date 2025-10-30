#include "WrapDecorator.h"

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

/*!
 *
 * @return Concrete clone of Decorator object
 */
PlantDecorator *WrapDecorator::clone() {
    Plant* newP = this->getWrapped()->clone();

    WrapDecorator* newD = new WrapDecorator();
    newD->setWrapped(newP);

    return newD;
}