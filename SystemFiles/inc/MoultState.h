#ifndef MOULTSTATE_H
#define MOULTSTATE_H

#include "PlantState.h"

/*!
 * @class MoultState
 *
 * @brief Intermediate state for plant object
 *
 * Reached by failing plant care tasks. Transitions to GrowingState, or plant object can be removed from the system
 */
class MoultState : public PlantState
{
public:
    void handleCare(Plant *plant);
    std::string getStateName();
};

#endif // MOULTSTATE_H