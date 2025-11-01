#include "../inc/SeedingState.h"
#include "../inc/Plant.h"
#include "../inc/PlantState.h"
#include "../inc/GrowingState.h"
#include "../inc/DeadState.h"
#include <iostream>

/*!
 * @brief Determines which state change should occur, if any, according to Plant->health
 *
 * Plant object can progress to GrowingState, or be removed from the system due to failed care
 * Called after any plant care function is executed
 *
 * @param plant Plant object for which the state is being checked (and perhaps changed)
 */
void SeedingState::handleCare(Plant *plant) {
    int hp = plant->getHealth();
    if (hp >= 2) {
        //go to GrowingState
        plant->changeState(new GrowingState);
    } else if (hp < 0) {
        cout << "Plant " + plant->getID() + " has died.\n";
        plant->changeState(new DeadState);
    }
}

/*!
 * @return "Seeding"
 */
std::string SeedingState::getStateName() {
    return "Seeding";
}