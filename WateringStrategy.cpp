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
    std::cout << "Watering the plant." << std::endl;
    return true;
}

/*!
 * @return Watering
 */
std::string WateringStrategy::getCareType() {
    return "Watering";
}