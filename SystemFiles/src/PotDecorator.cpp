#include "../inc/PotDecorator.h"
#include <iostream>

/*!
 * Return std::string gotten for wrappedPlant object, appended with "Decoration: Pot"
 *
 * @return Basic details of decorated plant
 */
std::string PotDecorator::getDetails()
{
    if (this->getWrapped() == nullptr)
    {
        std::cout << "PotDecorator::getDetails() returning error message (no wrapped plant)\n";
        return "Plant to be decorated has not been set";
    }

    std::string det = getWrapped()->getDetails();
    det += "Decoration: Pot \n";

    return det;
}

/*!
 * @brief Calculates the price as wrappedPlant->price + 20.00
 *
 * @return Full price of decorated plant
 */
double PotDecorator::getCost()
{
    if (this->getWrapped() == nullptr)
    {
        std::cout << "PotDecorator::getCost() returning 0 (no wrapped plant)\n";
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
PlantDecorator *PotDecorator::clone()
{
 /* //this is failing the clone tests
    std::cout << "Calling PotDecorator::clone()\n";

    Plant *newP = this->getWrapped()->clone();

    PotDecorator *newD = new PotDecorator();
    newD->setWrapped(newP);

    std::cout << "PotDecorator::clone() returning new PotDecorator with wrapped plant\n";
    return newD;
 */

    
    std::cout << "Calling PotDecorator::clone()\n";

    Plant *wrapped = this->getWrapped();
    Plant *newP = nullptr;

    //checking if wrapped plant is a decorator
    PlantDecorator *wrappedDecorator = dynamic_cast<PlantDecorator*>(wrapped);
    if (wrappedDecorator) {
        //yes: clone it as a decorator to preserve the chain
        newP = wrappedDecorator->clone();
    } else {
        //nah just regular: just clone it
        newP = wrapped->clone();
    }

    PotDecorator *newD = new PotDecorator();
    newD->setWrapped(newP);

    std::cout << "PotDecorator::clone() returning new PotDecorator with wrapped plant\n";
    return newD;
}