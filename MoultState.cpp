#include "MoultState.h"
#include "Plant.h"
#include "PlantState.h"
#include "GrowingState.h"
#include "DeadState.h"
#include <iostream>

/*!
 * @brief Determines which state change should occur, if any, according to Plant->health
 *
 * Plant object can progress back to GrowingState, or be removed from the system due to failed care
 * Called after any plant care function is executed
 *
 * @param plant Plant object for which the state is being checked (and perhaps changed)
 */
void MoultState::handleCare(Plant* plant) {
    int hp = plant->getHealth();
    if (hp <= 0) {
        //plant has died
        cout << "Plant " + plant->getID() + " has died.\n";
        plant->changeState(new DeadState);
    } else if (hp >= 3) {
        //go to growing state
        plant->changeState(new GrowingState);
    }
}

/*!
 * @return "Moulting"
 */
std::string MoultState::getStateName() {
    return "Moulting";
}