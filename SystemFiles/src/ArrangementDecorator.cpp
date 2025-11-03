#include "../inc/ArrangementDecorator.h"
#include <iostream>

/*!
 * Return string gotten for wrappedPlant object, appended with "Decoration: Arrangement"
 *
 * @return Basic details of decorated plant
 */
std::string ArrangementDecorator::getDetails()
{
    if (this->getWrapped() == nullptr)
    {
        std::cout << "ArrangementDecorator::getDetails() returning error message (no wrapped plant)\n";
        return "Plant to be decorated has not been set";
    }

    std::string det = getWrapped()->getDetails();
    det += "Decoration: Arrangement \n";

    return det;
}

/*!
 *
 * @return Concrete clone of Decorator object
 */
PlantDecorator *ArrangementDecorator::clone()
{

    /* //this is failing the clone tests
    Plant *newP = this->getWrapped()->clone();

    ArrangementDecorator *newD = new ArrangementDecorator();
    newD->setWrapped(newP);

    return newD;
    */

    Plant *wrapped = this->getWrapped();
    Plant *newP = nullptr;

    //checking first if wrapped plant is a decorator
    PlantDecorator *wrappedDecorator = dynamic_cast<PlantDecorator*>(wrapped);
    if (wrappedDecorator) {
        newP = wrappedDecorator->clone();
    } else {
        newP = wrapped->clone();
    }

    ArrangementDecorator *newD = new ArrangementDecorator();
    newD->setWrapped(newP);

    return newD;
}

/*!
 * @brief Calculates the price as wrappedPlant->price + 10.00
 *
 * @return Full price of decorated plant
 */
double ArrangementDecorator::getCost()
{
    if (this->getWrapped() == nullptr)
    {
        std::cout << "ArrangementDecorator::getCost() returning 0 (no wrapped plant)\n";
        return 0;
    }

    double cost = getWrapped()->getCost();
    cost += 10;

    return cost;
}