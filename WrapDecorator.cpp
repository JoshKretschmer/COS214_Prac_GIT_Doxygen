#include "WrapDecorator.h"
#include <iostream>

/*!
 * Return string gotten for wrappedPlant object, appended with "Decoration: Wrap"
 *
 * @return Basic details of decorated plant
 */
std::string WrapDecorator::getDetails()
{
    std::cout << "Calling WrapDecorator::getDetails()\n";

    if (this->getWrapped() == nullptr)
    {
        std::cout << "WrapDecorator::getDetails() returning error message (no wrapped plant)\n";
        return "Plant to be decorated has not been set";
    }

    std::string det = getWrapped()->getDetails();
    det += "Decoration: Wrap \n";

    std::cout << "WrapDecorator::getDetails() returning: \"" << det << "\"\n";
    return det;
}

/*!
 * @brief Calculates the price as wrappedPlant->price + 15.00
 *
 * @return Full price of decorated plant
 */
double WrapDecorator::getCost()
{
    std::cout << "Calling WrapDecorator::getCost()\n";

    if (this->getWrapped() == nullptr)
    {
        std::cout << "WrapDecorator::getCost() returning 0 (no wrapped plant)\n";
        return 0;
    }

    double cost = getWrapped()->getCost();
    cost += 15;

    std::cout << "WrapDecorator::getCost() returning " << cost << "\n";
    return cost;
}

/*!
 *
 * @return Concrete clone of Decorator object
 */
PlantDecorator *WrapDecorator::clone()
{
    std::cout << "Calling WrapDecorator::clone()\n";

    Plant *newP = this->getWrapped()->clone();

    WrapDecorator *newD = new WrapDecorator();
    newD->setWrapped(newP);

    std::cout << "WrapDecorator::clone() returning new WrapDecorator with wrapped plant\n";
    return newD;
}