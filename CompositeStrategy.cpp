#include "CompositeStrategy.h"
#include "SunlightStrategy.h"
#include "WateringStrategy.h"
#include "FertilizingStrategy.h"
#include <iostream>

/*!
 * @brief Basic constructor function
 */
CompositeCareStrategy::CompositeCareStrategy() {

}

/*!
 * @brief Runs execute() for all different strategies
 *
 * @return True
 */
bool CompositeCareStrategy::executeCare() {
    cout << "Executing composite care strategy:" << endl;
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
string CompositeCareStrategy::getCareType() {
    return "Composite";
}