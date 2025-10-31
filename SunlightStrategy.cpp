#include "SunlightStrategy.h"
#include <iostream>

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
    std::cout << "Providing sunlight to the plant." << std::endl;
    return true;
}

/*!
 * @return Sunlight
 */
std::string SunlightStrategy::getCareType() {
    return "Sunlight";
}