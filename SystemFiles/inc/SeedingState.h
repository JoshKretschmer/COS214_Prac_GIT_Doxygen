#ifndef SEEDINGSTATE_H
#define SEEDINGSTATE_H

#include "PlantState.h"

/*!
 * @class SeedingState
 *
 * @brief Initial state of all Plant objects
 *
 * Can change to GrowingState, or the object can be destroyed from here
 */
class SeedingState : public PlantState {
public:
    void handleCare(Plant* plant);
    std::string getStateName();
};

#endif //SEEDINGSTATE_H
