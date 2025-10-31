#include "Iterator.h"
#include "InventoryComponent.h"
#include "InventoryIterator.h"
#include "Inventory.h"
#include "PlantGroup.h"
#include <vector>

/*!
 * @brief Basic constructor function
 */
Inventory::Inventory() : InventoryComponent() {}

/*!
 * @brief Basic destructor function with memeory management
 */
Inventory::~Inventory() {
    for (auto p : plants) {
        delete p;
    }
    plants.clear();

    for (auto g : groups) {
        delete g;
    }
    groups.clear();
}

/*!
 * @param plant Add a Plant object directly to inventory (not categorized)
 */
void Inventory::addPlant(Plant* plant) {
    plants.push_back(plant);
}

/*!
 * @brief Searches Inventory for a Plant based on its ID
 *
 * @param plantId Plant to be removed from Inventory
 */
void Inventory::removePlant(std::string plantId) {
    for (auto it = plants.begin(); it != plants.end(); ++it) {
        if ((*it)->getDetails() == plantId) {
            Plant* removed = *it;
            plants.erase(it);
            delete removed; // free memory
            break;
        }
    }
}

/*!
 *
 * @param plantType Category for with to update the stock numbers
 * @param quantity Amount that the stockLevels is being updated to
 */
void Inventory::updateStock(std::string plantType, int quantity) {
    stockLevels[plantType] = quantity;
}

/*!
 *
 * @param plantType Category that the stock level is being requested for
 * @return Number of plants in the specified category
 */
int Inventory::getStockLevel(std::string plantType) {
    return stockLevels[plantType];
}

/*!
 * @return Iterator object for stepping through the Inventory
 */
InventoryIterator* Inventory::createIterator() {
    return new InventoryIterator(this);
}

// void Inventory::notifyObservers() {
//     // can notify Observer pattern if implemented
// }

/*!
 *
 * @return Total number of Plants in the Inventory (uncategorized)
 */
int Inventory::getPlantCount() {
    return plants.size();
}

/*!
 * @param component PlantGroup object to be added to Inventory
 */
void Inventory::add(InventoryComponent* component) {
    groups.push_back(dynamic_cast<PlantGroup*>(component));
}

/*!
 * @param component Plant Group to be removed from the Inventory
 */
void Inventory::remove(InventoryComponent* component) {
    auto it = std::find(groups.begin(), groups.end(), dynamic_cast<PlantGroup*>(component));
    if (it != groups.end()) {
        if (*it == component) delete *it;
        groups.erase(it);
    }
}

/*!
 *
 * @return All Plant objects in the Inventory (both categorized and not)
 */
vector<Plant*> Inventory::getPlants() {
    vector<Plant*> allPlants = plants;
    for (auto g : groups) {
        auto gPlants = g->getPlants();
        allPlants.insert(allPlants.end(), gPlants.begin(), gPlants.end());
    }
    return allPlants;
}

/*!
* @brief Changes the group a Plant is stored in based on a state change that has occurred
 *
 * @param plant Plant object to be moved
 * @param newState determines the group that the Plant object will be moved to
 */
void Inventory::movePlant(Plant* plant, std::string newState) {
    if (std::find(plants.begin(), plants.end(), plant) != plants.end()) {
        return ;// plant is in main inventory
    }

    for (auto g : groups) {
        g->movePlant(plant, newState);
    }
}