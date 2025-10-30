#include "DeadState.h"

/*!
 * @brief Placeholder function for dead plants that must be removed from system
 *
 * Exists to avoid errors that may be caused by attempting to care for a dead plant
 *
 * @param plant Plant object for which the state is being checked
 */
void DeadState::handleCare(Plant *plant) {
    cout << "Dead\n";
}

/*!
 * @return "Dead"
 */
string DeadState::getStateName() {
    return "Dead";
}