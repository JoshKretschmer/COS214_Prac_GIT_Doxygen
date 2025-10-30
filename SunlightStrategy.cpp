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
    cout << "Providing sunlight to the plant." << endl;
    return true;
}

/*!
 * @return Sunlight
 */
string SunlightStrategy::getCareType() {
    return "Sunlight";
}