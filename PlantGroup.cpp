#include "PlantGroup.h"
#include "InventoryComponent.h"
#include "Plant.h"
#include <algorithm>
#include <iostream>

/*!
 * @brief Basic constructor function
 *
 * @param name Name of PlantGroup(Category)
 */
PlantGroup::PlantGroup(std::string name)
    : InventoryComponent(), groupName(std::move(name))
{
    std::cout << "Calling PlantGroup Constructor (name=\"" << groupName << "\")\n";
}

/*!
 * @brief Basic destructor function
 */
PlantGroup::~PlantGroup()
{
    std::cout << "Calling PlantGroup Deconstructor (name=\"" << groupName << "\")\n";
    for (auto c : children) delete c;
    children.clear();
}

/*!
 * @brief Adds a Plant object or another PlantGroup to the category
 *
 * @param component Plant* or PlantGroup*
 */
void PlantGroup::add(InventoryComponent* component)
{
    std::cout << "Calling PlantGroup::add(component="
              << (component ? "non-null" : "null") << ")\n";
    if (!component) return;
    children.push_back(component);
}

/*!
 * @brief Removes a Plant or a subgroup from the category
 *
 * @param component Plant* or PlantGroup* to be removed
 */
void PlantGroup::remove(InventoryComponent* component)
{
    std::cout << "Calling PlantGroup::remove(component="
              << (component ? "non-null" : "null") << ")\n";
    auto it = std::find(children.begin(), children.end(), component);
    if (it != children.end()) {
        delete *it;
        children.erase(it);
    }
}

/*!
 * @return All plant objects in the category (recursively)
 */
std::vector<Plant*> PlantGroup::getPlants()
{
    std::cout << "Calling PlantGroup::getPlants() - aggregating "
              << children.size() << " children\n";
    std::vector<Plant*> result;
    for (auto c : children) {
        auto sub = c->getPlants();
        result.insert(result.end(), sub.begin(), sub.end());
    }
    std::cout << "PlantGroup::getPlants() returning " << result.size() << " plants\n";
    return result;
}

/*!
 * @brief Moves a plant from one category to another due to a state change
 *
 * @param plant Plant object to be moved
 * @param newState state that determines the new category to store in
 */
void PlantGroup::movePlant(Plant* plant, std::string newState)
{
    std::cout << "Calling PlantGroup::movePlant(plant="
              << (plant ? plant->getDetails().c_str() : "null")
              << ", newState=\"" << newState << "\")\n";

    // Try to find the plant in any child and remove it
    for (auto it = children.begin(); it != children.end(); ++it) {
        auto sub = (*it)->getPlants();
        if (std::find(sub.begin(), sub.end(), plant) != sub.end()) {
            delete *it;               // the child owns the plant, delete it
            children.erase(it);
            break;
        }
    }

    // The plant is now "free" – client code should add it to the proper group
}
