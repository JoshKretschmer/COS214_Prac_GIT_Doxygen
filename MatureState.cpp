#include "MatureState.h"
#include "Plant.h"
#include "PlantState.h"
#include "MoultState.h"

/*!
 * @brief Determines which state change should occur, if any, according to Plant->health
 *
 * Plant object can regress to MoultState, or be removed from the system due to sale
 * Called after any plant care function is executed
 *
 * @param plant Plant object for which the state is being checked (and perhaps changed)
 */
void MatureState::handleCare(Plant* plant) {
    int hp = plant->getHealth();
    if (hp <= 2) {
        //go to MoultState
        plant->changeState(new MoultState);
    }
}

/*!
 * @return "Matured"
 */
string MatureState::getStateName() {
    return "Matured";
}