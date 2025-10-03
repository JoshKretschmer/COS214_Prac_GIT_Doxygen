/**
 * @file PlantIterator.h
 * @brief Defines the PlantIterator class for browsing plants.
 */
#ifndef PLANTITERATOR_H
#define PLANTITERATOR_H

#include "Plant.h"
#include <vector>

/**
 * @class PlantIterator
 * @brief Iterator to browse through the plant collection.
 */
class PlantIterator {
private:
    const std::vector<Plant>& plants;
    size_t position;

public:
    PlantIterator(const std::vector<Plant>& plants);
    bool hasNext() const;
    const Plant& next();
};

#endif
