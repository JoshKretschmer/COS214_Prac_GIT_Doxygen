#ifndef MEMENTO_H
#define MEMENTO_H

/*!
 * @headerfile Memento.h
 */

#include "Plant.h"
#include <vector>

/*!
 * @class Memento
 *
 * @brief Saves a copy of Plant objects for the purpose of undoing changes made to the Order objects
 */
class Memento {
private:
    vector<Plant*> savedPlants;
    double savedCost;

public:
    Memento(const std::vector<Plant*>& plants, double cost);
    ~Memento();
    const vector<Plant*>& getSavedPlants() const;
    double getSavedCost() const;
    vector<Plant*> getMementos() const { return savedPlants; }




#endif //MEMENTO_H
