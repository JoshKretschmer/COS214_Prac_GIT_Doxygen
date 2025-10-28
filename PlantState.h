#ifndef PLANTSTATE_H
#define PLANTSTATE_H

/*!
 * @headerfile PlantState.h
 */
#include "libraries.h"
#include "Plant.h"


class Plant;

/*!
 * @class PlantState
 *
 * @brief Abstract parent class for concrete state classes
 */
class PlantState
{
    public:
        PlantState();
        virtual ~PlantState();
        virtual int handleCare(Plant* plant)=0;
        virtual string getStateName()=0;
};

/*!
 * @class SeedingState
 *
 * @brief Initial state of all Plant objects
 *
 * Can change to GrowingState, or the object can be destroyed from here
 */
class SeedingState : public PlantState {
    public:
        SeedingState();
        virtual int handleCare(Plant* plant) override;
        virtual string getStateName() override;
};

/*!
 * @class GrowingState
 *
 * @brief Intermediate state for Plant objects
 *
 * Can transition to MoultState or MatureState
 */
class GrowingState : public SeedingState {
    public:
        GrowingState();
        virtual int handleCare(Plant* plant) override;
        virtual string getStateName() override;
};


/*!
 * @class MatureState
 *
 * @brief State in which Plant objects can be sold
 *
 * Can transition to MoultState, or be removed from system by a purchase action
 */
class MatureState : public SeedingState {
    public:
        MatureState();
        virtual int handleCare(Plant* plant) override;
        virtual string getStateName() override;
};

/*!
 * @class MoultState
 *
 * @brief Intermediate state for plant object
 *
 * Reached by failing plant care tasks. Transitions to GrowingState, or plant object can be removed from the system
 */
class MoultState : public SeedingState {
    public:
        MoultState();
        virtual int handleCare(Plant* plant) override;
        virtual string getStateName() override;
};

/*!
 * @class DeadState
 *
 * @brief Final state for plant object
 *
 * Reached by failing plant care tasks (hp >=0). Final state of plant with no outgoing transitions
 */
class DeadState : public PlantState {
public:
    virtual int handleCare(Plant* plant) override;
    virtual string getStateName() override;
};



#endif //PLANTSTATE_H