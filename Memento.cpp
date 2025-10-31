// Memento.cpp
#include "Memento.h"

/*!
 * @brief Constructs a Memento by deep-copying the given plants and cost.
 *
 * @param plants Current plants in the Order.
 * @param cost   Current total cost of the Order.
 */
Memento::Memento(const std::vector<Plant *> &plants, double cost)
{
    savedCost = cost;
    savedPlants.reserve(plants.size());
    for (auto *p : plants)
    {
        savedPlants.push_back(p->clone());
    }
}

/*!
 * @brief Destroys the Memento and frees all cloned plants.
 */
Memento::~Memento()
{
    for (auto *p : savedPlants)
    {
        delete p;
    }
}

/*!
 * @return Vector of cloned plants stored in this snapshot.
 */
const std::vector<Plant *> &Memento::getSavedPlants() const
{
    return savedPlants;
}

/*!
 * @return Total cost stored in this snapshot.
 */
double Memento::getSavedCost() const
{
    return savedCost;
}