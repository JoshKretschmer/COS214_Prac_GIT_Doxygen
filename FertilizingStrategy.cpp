#include "FertilizingStrategy.h"
#include <iostream>

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