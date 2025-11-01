#include "../inc/GrowingState.h"
#include "../inc/Plant.h"
#include "../inc/PlantState.h"
#include "../inc/MoultState.h"
#include "../inc/MatureState.h"
#include <iostream>

/*!
 * @brief Determines which state change should occur, if any, according to Plant->health
 *
 * Plant object can progress to MatureState, or regress to MoultState
 * Called after any plant care function is executed
 *
 * @param plant Plant object for which the state is being checked (and perhaps changed)
 */
void GrowingState::handleCare(Plant *plant)
{
    std::cout << "GrowingState: Checking health for plant ID " << plant->getID() << "\n";
    int hp = plant->getHealth();
    if (hp <= 1)
    {
        plant->changeState(new MoultState);
    }
    else if (hp >= 4)
    {
        plant->changeState(new MatureState);
    }
}

/*!
 * @return "Growing"
 */
std::string GrowingState::getStateName()
{
    std::cout << "Getting state name: Growing\n";
    return "Growing";
}