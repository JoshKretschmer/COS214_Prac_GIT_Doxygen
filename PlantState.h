/*!
 *  @headerfile PlantState.h
 *
 *  @brief Contains class definitions for the various states a Plant object can be in
 *
 *  Movements between state determined by Plant->health attribute, which is changes by plant care tasks
 *  Patterns: State
 */

#ifndef PLANTSTATE_H
#define PLANTSTATE_H

#include <string>
using namespace std;

/*!
 * @brief Forward declaration for Plant class to avoid circular dependency
 */
class Plant;

/*!
 * @class PlantState
 *
 * @brief Abstract parent class for concrete state classes
 */

//add dead state
class PlantState {
public:
    PlantState();
    virtual ~PlantState();
    void virtual handleCare(Plant* plant)=0;
    string virtual getStateName()=0;
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
    void handleCare(Plant* plant);
    string getStateName();
};

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
    string getStateName();
};

/*!
 * @class MatureState
 *
 * @brief State in which Plant objects can be sold
 *
 * Can transition to MoultState, or be removed from system by a purchase action
 */
class MatureState : public PlantState {
public:
    void handleCare(Plant* plant);
    string getStateName();
};

/*!
 * @class MoultState
 *
 * @brief Intermediate state for plant object
 *
 * Reached by failing plant care tasks. Transitions to GrowingState, or plant object can be removed from the system
 */
class MoultState : public PlantState {
public:
    void handleCare(Plant* plant);
    string getStateName();
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
    void handleCare(Plant* plant);
    string getStateName();
};



#endif //PLANTSTATE_H
