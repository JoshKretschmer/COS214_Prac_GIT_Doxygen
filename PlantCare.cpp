#include "PlantCare.h"
#include <iostream>

using namespace std;

/*!
 * @brief Basic Abstract class constructor
 */
PlantCare::PlantCare() {

}

//#############################################

/*!
 * @brief Basic constructor function
 */
SunlightStrategy::SunlightStrategy() {

}

/*!
 *
 * @return Output message and return true
 */
bool SunlightStrategy::executeCare() {
    cout << "Providing sunlight to the plant." << endl;
    return true;
}

/*!
 * @return Sunlight
 */
string SunlightStrategy::getCareType() {
    return "Sunlight";
}

//#############################################

/*!
 * @brief Basic constructor function
 */
WateringStrategy::WateringStrategy() {

}

/*!
 *
 * @return Output message and return true
 */
bool WateringStrategy::executeCare() {
    cout << "Watering the plant." << endl;
    return true;
}

/*!
 * @return Watering
 */
string WateringStrategy::getCareType() {
    return "Watering";
}

//#############################################

/*!
 * @brief Basic constructor function
 */
FertilizingStrategy::FertilizingStrategy() {

}

/*!
 *
 * @return Output message and return true
 */
bool FertilizingStrategy::executeCare() {
    cout << "Fertilizing the plant." << endl;
    return true;
}

/*!
 * @return Fertilizing
 */
string FertilizingStrategy::getCareType() {
    return "Fertilizing";
}

//#############################################

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

/*!
 * @brief Basic destructor function
 */
PlantCare::~PlantCare() {}