#include "../inc/WrapDecorator.h"
#include <iostream>

/*!
 * Return string gotten for wrappedPlant object, appended with "Decoration: Wrap"
 *
 * @return Basic details of decorated plant
 */
std::string WrapDecorator::getDetails()
{
    if (this->getWrapped() == nullptr)
    {
        std::cout << "WrapDecorator::getDetails() returning error message (no wrapped plant)\n";
        return "Plant to be decorated has not been set";
    }

    std::string det = getWrapped()->getDetails();
    det += "Decoration: Wrap \n";

    return det;
}

/*!
 * @brief Calculates the price as wrappedPlant->price + 15.00
 *
 * @return Full price of decorated plant
 */
double WrapDecorator::getCost()
{
    if (this->getWrapped() == nullptr)
    {
        std::cout << "WrapDecorator::getCost() returning 0 (no wrapped plant)\n";
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
PlantDecorator *WrapDecorator::clone()
{
    /* // this is failing the clone tests
    Plant *newP = this->getWrapped()->clone();

    WrapDecorator *newD = new WrapDecorator();
    newD->setWrapped(newP);

    return newD;
    */

    Plant *wrapped = this->getWrapped();
    Plant *newP = nullptr;

    //is wrapped plant a decorator
    PlantDecorator *wrappedDecorator = dynamic_cast<PlantDecorator*>(wrapped);
    if (wrappedDecorator) {
        newP = wrappedDecorator->clone();
    } else {
        newP = wrapped->clone();
    }

    WrapDecorator *newD = new WrapDecorator();
    newD->setWrapped(newP);

    return newD;

}