#ifndef INVENTORY_H
#define INVENTORY_H


#include "Plant.h"
#include <vector>


class PlantIterator;


/**
* @class Inventory
* @brief Stores and manages a collection of plants.
*/
class Inventory {
private:
std::vector<Plant> plants;
public:
void addPlant(const Plant& plant);
void removePlant(int plantId);
PlantIterator createIterator() const;
const std::vector<Plant>& getPlants() const;
};


#endif