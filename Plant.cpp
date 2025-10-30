#include "Plant.h"
#include "SeedingState.h"
#include "CompositeStrategy.h"
#include "HouseLeek.h"
#include "PeanutCactus.h"
#include "Orchid.h"
#include "Marigold.h"
#include "BeeBlossom.h"
#include "HoneySuckle.h"

/*!
 * @brief Plant constructor function
 *
 * Initializes information shared by all plants (health, currState, careRegime)
 */
Plant::Plant() {
    health = 0;
    currState = new SeedingState();
    careRegime = new CompositeCareStrategy();
}

/*!
 * @brief Destructor for Plant class
 */
Plant::~Plant() {
    delete currState;
    delete careRegime;
}

/*!
 * @brief Changes the state of the Plant object
 *
 * Called in the PlantState class
 *
 * @param newState State that Plant object is being set to
 */
void Plant::changeState(PlantState *newState) {
    newState->getStateName();
    delete currState;
    this->currState=newState;
}

/*!
 * @brief If a Plant is not fully grown, care is still needed
 *
 * Exception case where plant is dead is accounted for in the first if
 *
 * @return bool stating whether care is needed
 */
bool Plant::needsCare() {
    if (this->getState() == "Dead") {
        return false;
    }

    if (this->health <5) {
        return true;
    }
    return false;
}


/*!
 * @brief Increase the health of a plant by num
 *
 * Done after a care task is successfully done.
 * currState->handleCare() is called to ensure that state changes occur as needed
 *
 * @param num amount with which to increase health (negative number used for decrease)
 */
void Plant::incrementHealth(int num) {
    this->health= this->health + num;
    this->currState->handleCare(this);
}

/*!
 * @return name of the current state of the plant as a string
 */
string Plant::getState() {
    return currState->getStateName();
}

/*!
 * @return Concrete copy of Plant object
 */
Plant *Plant::clone() {
    Plant *newPlant;

    if (this->type == "Succulent") {
        if (this->getID().substr(0,2) == "PC") {
            newPlant = new PeanutCactus();
        } else if (this->getID().substr(0,2) == "HL") {
            newPlant = new HouseLeek();
        }
    } else if (this->type == "Flower") {
        if (this->getID().substr(0,2) == "OR") {
            newPlant = new Orchid();
        } else if (this->getID().substr(0,2) == "MG") {
            newPlant = new Marigold();
        }
    } else if (this->type == "Shrub") {
        if (this->getID().substr(0,2) == "BB") {
            newPlant = new BeeBlossom();
        } else if (this->getID().substr(0,2) == "HS") {
            newPlant = new HoneySuckle();
        }
    }

    newPlant->id = this->id;
    newPlant->type = this->type;   //redundancy for double-checking
    newPlant->price = this->price;
    newPlant->currState = this->currState;
    newPlant->careRegime = this->careRegime;
    newPlant->health = this->health;

    return newPlant;
}