#ifndef GROWINGSTATE_H
#define GROWINGSTATE_H

#include "PlantState.h"

/*!
 * @class GrowingState
 *
 * @brief Intermediate state for Plant objects
 *
 * Can transition to MoultState or MatureState
 */
class GrowingState : public PlantState {
public:
    void handleCare(Plant* plant);
    std::string getStateName();
};

#endif //GROWINGSTATE_H
