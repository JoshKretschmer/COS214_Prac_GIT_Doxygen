#include "Memento.h"

/*!
 * @brief Basic Memento creator function
 *
 * @param plants Plant objects to be stored from the Order Object
 * @param cost Total cost of all Plant objects to be stored
 */
Memento::Memento(const vector<Plant*>& plants, double cost) {
    savedCost = cost;
    // Deep copy plants to avoid external modification
    for (auto plant : plants) {
        savedPlants.push_back(plant->clone());
    }
}

/*!
 * @brief Basic Memento destructor
 */
Memento::~Memento() {
    // Cleanup if necessary
    for (auto plant : savedPlants) {
        delete plant; // Assuming Plant is dynamically allocated
    }
    savedCost = 0;
}

/*!
 *
 * @return Plant objects stored in the Memento
 */
const vector<Plant*>& Memento::getSavedPlants() const {
    return savedPlants;
}

/*!
 *
 * @return Cost of Plant objects stored in Memento
 */
double Memento::getSavedCost() const {
    return savedCost;
}
