#include "Inventory.h"
#include "PlantIterator.h"
#include <algorithm> // for remove_if


void Inventory::addPlant(const Plant& plant) {
plants.push_back(plant);
}


void Inventory::removePlant(int plantId) {
    plants.erase(std::remove_if(plants.begin(), plants.end(),
                                [plantId](const Plant& p) {
                                    return p.getId() == plantId;
                                }),
                 plants.end());
}



PlantIterator Inventory::createIterator() const {
return PlantIterator(plants);
}


const std::vector<Plant>& Inventory::getPlants() const {
return plants;
}