#include "../inc/MoultState.h"
#include "../inc/Plant.h"
#include "../inc/PlantState.h"
#include "../inc/GrowingState.h"
#include "../inc/DeadState.h"
#include <iostream>

/*!
 * @brief Determines which state change should occur, if any, according to Plant->health
 *
 * Plant object can progress back to GrowingState, or be removed from the system due to failed care
 * Called after any plant care function is executed
 *
 * @param plant Plant object for which the state is being checked (and perhaps changed)
 */
void MoultState::handleCare(Plant *plant)
{
    std::cout << "MoultState: Checking health for plant ID " << plant->getID() << "\n";
    int hp = plant->getHealth();
    if (hp <= 0)
    {
        cout << "Plant " + plant->getID() + " has died.\n";
        plant->changeState(new DeadState);
    }
    else if (hp >= 3)
    {
        plant->changeState(new GrowingState);
    }
}

/*!
 * @return "Moulting"
 */
std::string MoultState::getStateName()
{
    std::cout << "Getting state name: Moulting\n";
    return "Moulting";
}