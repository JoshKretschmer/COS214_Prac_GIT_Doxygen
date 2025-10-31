#include "CompositeStrategy.h"
#include "SunlightStrategy.h"
#include "WateringStrategy.h"
#include "FertilizingStrategy.h"
#include <iostream>

/*!
 * @brief Basic constructor function
 */
CompositeCareStrategy::CompositeCareStrategy()
{
}

/*!
 * @brief Runs execute() for all different strategies
 *
 * @return True
 */
bool CompositeCareStrategy::executeCare()
{
    std::cout << "Executing composite care strategy:" << std::endl;
    SunlightStrategy sunlight;
    WateringStrategy water;
    FertilizingStrategy fertilize;

    sunlight.executeCare();
    water.executeCare();
    fertilize.executeCare();

    return true;
}

/*!
 * @return Composite
 */
std::string CompositeCareStrategy::getCareType()
{
    return "Composite";
}

PlantCare *CompositeCareStrategy::clone() const
{
    std::cout << "Cloning CompositeCareStrategy\n";
    CompositeCareStrategy *copy = new CompositeCareStrategy();
    return copy;
}
