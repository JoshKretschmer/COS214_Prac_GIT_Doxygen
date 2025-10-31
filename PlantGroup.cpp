#include "PlantGroup.h"
#include "InventoryComponent.h"
#include "Plant.h"

/*!
 * @brief Basic constructor function
 *
 * @param name Name of PlantGroup(Category)
 */
PlantGroup::PlantGroup( std::string name) : InventoryComponent(), groupName(name) {}

/*!
 * @brief Basic destructor function
 */
PlantGroup::~PlantGroup() {
    for (auto c : children) {
        delete c;
    }
    children.clear();
}

/*!
 * @brief Adds a Plant object to the category group
 *
 * @param component Plant object to be added
 */
void PlantGroup::add(InventoryComponent* component) {
    if (!component)
        return;
    children.push_back(component);
}

/*!
 * @brief Finds a Plant object in the category and removes it
 *
 * @param component Plant object to be removed
 */
void PlantGroup::remove(InventoryComponent* component) {
    auto it = std::find(children.begin(), children.end(), component);
    if (it != children.end()) {
        if (*it == component)
            delete *it;
        children.erase(it);
    }
}

/*!
 * @return All plant objects in the category
 */
vector<Plant*> PlantGroup::getPlants() {
    vector<Plant*> result;
    for (auto c : children) {
        auto cPlants = c->getPlants();
        result.insert(result.end(), cPlants.begin(), cPlants.end());
    }
    return result;
}

/*!
 * @brief Moves a plant from one category to another due to a state change
 *
 * @param plant Plant object to be moved
 * @param newState state that determines the new category to store in
 */
void PlantGroup::movePlant(Plant* plant,  std::string newState) {
    for (auto c : children) {
        c->movePlant(plant, newState);
    }

}