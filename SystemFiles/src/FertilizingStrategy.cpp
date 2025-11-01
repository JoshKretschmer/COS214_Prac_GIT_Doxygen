#include "../inc/FertilizingStrategy.h"
#include <iostream>

/*!
 * @brief Basic constructor function
 */
FertilizingStrategy::FertilizingStrategy()
{
}

/*!
 *
 * @return Output message and return true
 */
bool FertilizingStrategy::executeCare()
{
    std::cout << "Fertilizing the plant." << std::endl;
    return true;
}

/*!
 * @return Fertilizing
 */
std::string FertilizingStrategy::getCareType()
{
    return "Fertilizing";
}

PlantCare *FertilizingStrategy::clone() const
{
    std::cout << "Cloning FertilizingStrategy\n";
    return new FertilizingStrategy();
}