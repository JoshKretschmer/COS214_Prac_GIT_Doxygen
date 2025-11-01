#include "../inc/ArrangementDecorator.h"
#include <iostream>

/*!
 * Return string gotten for wrappedPlant object, appended with "Decoration: Arrangement"
 *
 * @return Basic details of decorated plant
 */
std::string ArrangementDecorator::getDetails()
{
    std::cout << "Calling ArrangementDecorator::getDetails()\n";

    if (this->getWrapped() == nullptr)
    {
        std::cout << "ArrangementDecorator::getDetails() returning error message (no wrapped plant)\n";
        return "Plant to be decorated has not been set";
    }

    std::string det = getWrapped()->getDetails();
    det += "Decoration: Arrangement \n";

    std::cout << "ArrangementDecorator::getDetails() returning: \"" << det << "\"\n";
    return det;
}

/*!
 *
 * @return Concrete clone of Decorator object
 */
PlantDecorator *ArrangementDecorator::clone()
{
    std::cout << "Calling ArrangementDecorator::clone()\n";

    Plant *newP = this->getWrapped()->clone();

    ArrangementDecorator *newD = new ArrangementDecorator();
    newD->setWrapped(newP);

    std::cout << "ArrangementDecorator::clone() returning new ArrangementDecorator with wrapped plant\n";
    return newD;
}

/*!
 * @brief Calculates the price as wrappedPlant->price + 10.00
 *
 * @return Full price of decorated plant
 */
double ArrangementDecorator::getCost()
{
    std::cout << "Calling ArrangementDecorator::getCost()\n";

    if (this->getWrapped() == nullptr)
    {
        std::cout << "ArrangementDecorator::getCost() returning 0 (no wrapped plant)\n";
        return 0;
    }

    double cost = getWrapped()->getCost();
    cost += 10;

    std::cout << "ArrangementDecorator::getCost() returning " << cost << "\n";
    return cost;
}