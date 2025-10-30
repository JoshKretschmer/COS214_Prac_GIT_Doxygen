#include "WateringStrategy.h"
#include <iostream>

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