#include "ArrangementDecorator.h"

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
 *
 * @return Concrete clone of Decorator object
 */
PlantDecorator* ArrangementDecorator::clone() {
    Plant* newP = this->getWrapped()->clone();

    ArrangementDecorator* newD = new ArrangementDecorator();
    newD->setWrapped(newP);

    return newD;
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