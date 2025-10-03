#include "PlantIterator.h"

PlantIterator::PlantIterator(const std::vector<Plant>& plants)
    : plants(plants), position(0) {}

bool PlantIterator::hasNext() const {
    return position < plants.size();
}

const Plant& PlantIterator::next() {
    return plants[position++];
}
