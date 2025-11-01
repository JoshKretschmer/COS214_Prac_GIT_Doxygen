// Memento.h
#ifndef MEMENTO_H
#define MEMENTO_H

#include "Plant.h"
#include <vector>

/*!
 * @class Memento
 *
 * @brief Stores a snapshot of an Order's state for undo/redo.
 */
class Memento
{
private:
    std::vector<Plant *> savedPlants;
    double savedCost;

public:
    Memento(const std::vector<Plant *> &plants, double cost);
    ~Memento();

    const std::vector<Plant *> &getSavedPlants() const;
    double getSavedCost() const;
};

#endif // MEMENTO_H