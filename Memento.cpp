#include "Memento.h"
#include <iostream>
#include <vector>

/*!
 * @brief Constructs a Memento by deep-copying the given plants and cost.
 *
 * @param plants Current plants in the Order.
 * @param cost   Current total cost of the Order.
 */
Memento::Memento(const std::vector<Plant *> &plants, double cost)
{
    std::cout << "Calling Memento Constructor (plants.size()=" << plants.size()
              << ", cost=" << cost << ")\n";
    savedCost = cost;
    savedPlants.reserve(plants.size());
    for (auto *p : plants)
    {
        savedPlants.push_back(p->clone());
    }
    std::cout << "Memento Constructor cloned " << savedPlants.size() << " plants\n";
}

/*!
 * @brief Destroys the Memento and frees all cloned plants.
 */
Memento::~Memento()
{
    std::cout << "Calling Memento Deconstructor - deleting "
              << savedPlants.size() << " cloned plants\n";
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
    std::cout << "Calling Memento::getSavedPlants() - size=" << savedPlants.size() << "\n";
    return savedPlants;
}

/*!
 * @return Total cost stored in this snapshot.
 */
double Memento::getSavedCost() const
{
    std::cout << "Calling Memento::getSavedCost() returning " << savedCost << "\n";
    return savedCost;
}