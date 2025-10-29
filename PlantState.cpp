/*!
*  @file PlantState.cpp
 *
 * @brief Contains function definitions for the PlantState functions defined in PlantState.h
 */

#include "PlantState.h"
#include "Plant.h"
#include <iostream>


/*!
 * @brief Basic constructor for PlantState class
 */
PlantState::PlantState() {

}

/*!
 * @brief Basic destructor for PlantState class
 */
PlantState::~PlantState() {

}


//################################################

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
string SeedingState::getStateName() {
    return "Seeding";
}


//################################################

/*!
 * @brief Determines which state change should occur, if any, according to Plant->health
 *
 * Plant object can progress to MatureState, or regress to MoultState
 * Called after any plant care function is executed
 *
 * @param plant Plant object for which the state is being checked (and perhaps changed)
 */
void GrowingState::handleCare(Plant* plant) {
    int hp = plant->getHealth();
    if (hp <=1) {
        //go to moult state
        plant->changeState(new MoultState);
    } else if (hp >= 4) {
        //go to matureState
        plant->changeState(new MatureState);
    }
}

/*!
 * @return "Growing"
 */
string GrowingState::getStateName() {
    return "Growing";
}


//################################################

/*!
 * @brief Determines which state change should occur, if any, according to Plant->health
 *
 * Plant object can regress to MoultState, or be removed from the system due to sale
 * Called after any plant care function is executed
 *
 * @param plant Plant object for which the state is being checked (and perhaps changed)
 */
void MatureState::handleCare(Plant* plant) {
    int hp = plant->getHealth();
    if (hp <= 2) {
        //go to MoultState
        plant->changeState(new MoultState);
    }
}

/*!
 * @return "Matured"
 */
string MatureState::getStateName() {
    return "Matured";
}


//################################################

/*!
 * @brief Determines which state change should occur, if any, according to Plant->health
 *
 * Plant object can progress back to GrowingState, or be removed from the system due to failed care
 * Called after any plant care function is executed
 *
 * @param plant Plant object for which the state is being checked (and perhaps changed)
 */
void MoultState::handleCare(Plant* plant) {
    int hp = plant->getHealth();
    if (hp <= 0) {
        //plant has died
        cout << "Plant " + plant->getID() + " has died.\n";
        plant->changeState(new DeadState);
    } else if (hp >= 3) {
        //go to growing state
        plant->changeState(new GrowingState);
    }
}

/*!
 * @return "Moulting"
 */
string MoultState::getStateName() {
    return "Moulting";
}

//################################################

/*!
 * @brief Placeholder function for dead plants that must be removed from system
 *
 * Exists to avoid errors that may be caused by attempting to care for a dead plant
 *
 * @param plant Plant object for which the state is being checked
 */
void DeadState::handleCare(Plant *plant) {
    cout << "Dead\n";
}

/*!
 * @return "Dead"
 */
string DeadState::getStateName() {
    return "Dead";
}