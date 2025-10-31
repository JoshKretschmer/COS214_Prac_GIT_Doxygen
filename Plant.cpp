#include "Plant.h"
#include "SeedingState.h"
#include "CompositeStrategy.h"
#include "HouseLeek.h"
#include "PeanutCactus.h"
#include "Orchid.h"
#include "Marigold.h"
#include "BeeBlossom.h"
#include "HoneySuckle.h"
#include "GrowingState.h"
#include "MatureState.h"
#include "MoultState.h"
#include "DeadState.h"
#include <iostream>

/*!
 * @brief Plant constructor function
 *
 * Initializes information shared by all plants (health, currState, careRegime)
 */
Plant::Plant()
{
    std::cout << "Constructing a Plant (health=0, seeding state, composite care)\n";
    health = 0;
    currState = new SeedingState();
    careRegime = new CompositeCareStrategy();
}

/*!
 * @brief Destructor for Plant class
 */
Plant::~Plant()
{
    std::cout << "Destroying Plant (ID: " << id << ", Type: " << type << ")\n";
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
void Plant::changeState(PlantState *newState)
{
    std::cout << "Changing plant state from '" << currState->getStateName()
              << "' to '" << newState->getStateName() << "'\n";
    delete currState;
    this->currState = newState;
}

/*!
 * @brief If a Plant is not fully grown, care is still needed
 *
 * Exception case where plant is dead is accounted for in the first if
 *
 * @return bool stating whether care is needed
 */
bool Plant::needsCare()
{
    std::cout << "Checking if plant needs care (health=" << health << ", state=" << getState() << ")\n";
    if (this->getState() == "Dead")
    {
        return false;
    }
    if (this->health < 5)
    {
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
void Plant::incrementHealth(int num)
{
    std::cout << "Incrementing plant health by " << num << " (was " << health << ")";
    this->health = this->health + num;
    std::cout << " -> now " << health << "\n";
    this->currState->handleCare(this);
}

/*!
 * @return name of the current state of the plant as a string
 */
std::string Plant::getState()
{
    std::cout << "Getting current plant state\n";
    return currState->getStateName();
}

/*!
 * @return Concrete copy of Plant object
 */
Plant *Plant::clone()
{
    std::cout << "Cloning plant: " << type << " (ID: " << id << ")\n";

    Plant *newPlant = nullptr;

    if (this->type == "Succulent")
    {
        if (this->getID().substr(0, 2) == "PC")
            newPlant = new PeanutCactus();
        else if (this->getID().substr(0, 2) == "HL")
            newPlant = new HouseLeek();
    }
    else if (this->type == "Flower")
    {
        if (this->getID().substr(0, 2) == "OR")
            newPlant = new Orchid();
        else if (this->getID().substr(0, 2) == "MG")
            newPlant = new Marigold();
    }
    else if (this->type == "Shrub")
    {
        if (this->getID().substr(0, 2) == "BB")
            newPlant = new BeeBlossom();
        else if (this->getID().substr(0, 2) == "HS")
            newPlant = new HoneySuckle();
    }

    if (newPlant)
    {
        newPlant->id = this->id;
        newPlant->type = this->type;
        newPlant->price = this->price;
        newPlant->health = this->health;

        delete newPlant->currState;
        delete newPlant->careRegime;
        newPlant->currState = nullptr;
        newPlant->careRegime = nullptr;

        std::string stateName = this->currState->getStateName();
        if (stateName == "Seeding")
            newPlant->currState = new SeedingState();
        else if (stateName == "Growing")
            newPlant->currState = new GrowingState();
        else if (stateName == "Mature")
            newPlant->currState = new MatureState();
        else if (stateName == "Moulting")
            newPlant->currState = new MoultState();
        else if (stateName == "Dead")
            newPlant->currState = new DeadState();

        newPlant->careRegime = this->careRegime->clone();
    }

    return newPlant;
}

void Plant::add(InventoryComponent *)
{
    std::cout << "Calling Plant::add() - ignored (leaf node)\n";
}

void Plant::remove(InventoryComponent *)
{
    std::cout << "Calling Plant::remove() - ignored (leaf node)\n";
}

std::vector<Plant *> Plant::getPlants()
{
    std::cout << "Calling Plant::getPlants() - returning this plant\n";
    return {this};
}

void Plant::movePlant(Plant *, std::string)
{
    std::cout << "Calling Plant::movePlant() - ignored (leaf node)\n";
}