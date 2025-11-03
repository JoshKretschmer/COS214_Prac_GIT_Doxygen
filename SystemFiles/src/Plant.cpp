#include "../inc/Plant.h"
#include "../inc/SeedingState.h"
#include "../inc/CompositeStrategy.h"
#include "../inc/HouseLeek.h"
#include "../inc/PeanutCactus.h"
#include "../inc/Orchid.h"
#include "../inc/Marigold.h"
#include "../inc/BeeBlossom.h"
#include "../inc/HoneySuckle.h"
#include "../inc/GrowingState.h"
#include "../inc/MatureState.h"
#include "../inc/MoultState.h"
#include "../inc/DeadState.h"
#include <iostream>

/*!
 * @brief Plant constructor function
 *
 * Initializes information shared by all plants (health, currState, careRegime)
 */
Plant::Plant() : id(""), type(""), price(0.0), health(0)
{
    currState = new SeedingState();
    careRegime = new CompositeCareStrategy();
}

/*!
 * @brief Destructor for Plant class
 */
Plant::~Plant()
{
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
    
    return currState->getStateName();
}

/*!
 * @return Concrete copy of Plant object
 */
Plant *Plant::clone()
{
    Plant *newPlant = nullptr;

    if (type == "Succulent")
    {
        if (id.substr(0, 2) == "HL")
            newPlant = new HouseLeek();
        else if (id.substr(0, 2) == "PC")
            newPlant = new PeanutCactus();
    }
    else if (type == "Orchid")
    {
        if (id.substr(0, 2) == "OR")
            newPlant = new Orchid();
        else if (id.substr(0, 2) == "MG")
            newPlant = new Marigold();
    }
    else if (type == "Shrub")
    {
        if (id.substr(0, 2) == "BB")
            newPlant = new BeeBlossom();
        else if (id.substr(0, 2) == "HS")
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

        if (this->currState)
        {
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
            else
            {
                std::cerr << "Plant::clone() - unknown state: " << stateName << "\n";
                newPlant->currState = new SeedingState(); // Default state
            }
        }
        else
        {
            std::cout << "Plant::clone() - currState is null, setting default SeedingState\n";
            newPlant->currState = new SeedingState();
        }

        if (this->careRegime)
        {
            newPlant->careRegime = this->careRegime->clone();
            std::cout << "Plant::clone() cloned careRegime\n";
        }
        else
        {
            std::cout << "Plant::clone() - careRegime is null, setting default CompositeCareStrategy\n";
            newPlant->careRegime = new CompositeCareStrategy();
        }
    }
    else
    {
        //std::cerr << "Plant::clone() - failed to create new plant for type: "
                  //<< (type.empty() ? "none" : type) << "\n";
    }

    return newPlant;
}
/*!
 * @brief Adds an InventoryComponent (ignored for leaf node)
 */
void Plant::add(InventoryComponent *)
{
    std::cout << "Calling Plant::add() - ignored (leaf node)\n";
}
/*!
 * @brief Removes an InventoryComponent (ignored for leaf node)
 */
void Plant::remove(InventoryComponent *)
{
    std::cout << "Calling Plant::remove() - ignored (leaf node)\n";
}
/*!
 * @brief Gets the plants in this component
 */
std::vector<Plant *> Plant::getPlants()
{
    std::cout << "Calling Plant::getPlants() - returning this plant\n";
    return {this};
}

/*!
 * @brief Moves a plant to a new state (ignored for leaf node)
 */
void Plant::movePlant(Plant *, std::string)
{
    std::cout << "Calling Plant::movePlant() - ignored (leaf node)\n";
}