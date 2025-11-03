#ifndef MATURESTATE_H
#define MATURESTATE_H

#include "PlantState.h"

/*!
 * @class MatureState
 *
 * @brief State in which Plant objects can be sold
 *
 * Can transition to MoultState, or be removed from system by a purchase action
 */
class MatureState : public PlantState
{
public:
    void handleCare(Plant *plant);
    std::string getStateName();
};

#endif // MATURESTATE_H