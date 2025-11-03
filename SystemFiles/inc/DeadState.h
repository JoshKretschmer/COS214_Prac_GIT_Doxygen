#ifndef DEADSTATE_H
#define DEADSTATE_H

#include "PlantState.h"

/*!
 * @class DeadState
 *
 * @brief Final state for plant object
 *
 * Reached by failing plant care tasks (hp >=0). Final state of plant with no outgoing transitions
 */
class DeadState : public PlantState {
public:
    void handleCare(Plant* plant);
    std::string getStateName();
};

#endif //DEADSTATE_H
