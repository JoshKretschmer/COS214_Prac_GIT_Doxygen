#include "GrowingState.h"
#include "Plant.h"
#include "PlantState.h"
#include "MoultState.h"
#include "MatureState.h"

/*!
 * @brief Determines which state change should occur, if any, according to Plant->health
 *
 * Plant object can progress to MatureState, or regress to MoultState
 * Called after any plant care function is executed
 *
 * @param plant Plant object for which the state is being checked (and perhaps changed)
 */
void GrowingState::handleCare(Plant* plant) {
    int hp = plant->getHealth();
    if (hp <=1) {
        //go to moult state
        plant->changeState(new MoultState);
    } else if (hp >= 4) {
        //go to matureState
        plant->changeState(new MatureState);
    }
}

/*!
 * @return "Growing"
 */
std::string GrowingState::getStateName() {
    return "Growing";
}