#include "../inc/Inventory.h"
#include "../inc/PlantGroup.h"
#include "../inc/InventoryIterator.h"
#include "../inc/Plant.h"
#include <algorithm>
#include <iostream>

/*!
 * @brief Basic constructor function
 */
Inventory::Inventory() : InventoryComponent()
{
}

/*!
 * @brief Basic destructor function with memory management
 */
Inventory::~Inventory()
{
    for (auto p : plants)
        delete p;
    plants.clear();

    for (auto g : groups)
        delete g;
    groups.clear();
}

/*!
 * @param plant Add a Plant object directly to inventory (not categorized)
 */
void Inventory::addPlant(Plant *plant)
{
    if (plant)
        plants.push_back(plant);
}

/*!
 * @brief Searches Inventory for a Plant based on its ID
 *
 * @param plantId Plant to be removed from Inventory
 */
void Inventory::removePlant(std::string plantId)
{
    auto it = std::find_if(plants.begin(), plants.end(),
                           [&](Plant *p)
                           { return p->getID() == plantId; });
    if (it != plants.end())
    {
        delete *it;
        plants.erase(it);
    }
}

/*!
 * @param plantType Category for with to update the stock numbers
 * @param quantity Amount that the stockLevels is being updated to
 */
void Inventory::updateStock(std::string plantType, int quantity)
{
    stockLevels[plantType] = quantity;
}

/*!
 * @param plantType Category that the stock level is being requested for
 * @return Number of plants in the specified category
 */
int Inventory::getStockLevel(std::string plantType)
{
    int lvl = stockLevels[plantType];
    return lvl;
}

/*!
 * @return Iterator object for stepping through the Inventory
 */
InventoryIterator *Inventory::createIterator()
{
    return new InventoryIterator(this);
}

/*!
 * @return Total number of Plants in the Inventory (uncategorized)
 */
int Inventory::getPlantCount()
{
    int cnt = static_cast<int>(plants.size());
    return cnt;
}

/*!
 * @param component Plant* or PlantGroup* to be added to Inventory
 */
void Inventory::add(InventoryComponent *component)
{
    if (!component)
        return;

    // If a raw Plant* is passed, treat it as a leaf
    Plant *p = dynamic_cast<Plant *>(component);
    if (p)
    {
        // put it in a default "Misc" group if no groups exist
        PlantGroup *misc = nullptr;
        for (auto g : groups)
        {
            if (g->getName() == "Misc")
            {
                misc = g;
                break;
            }
        }
        if (!misc)
        {
            misc = new PlantGroup("Misc");
            groups.push_back(misc);
        }
        misc->add(p);
        return;
    }

    // Otherwise it must be a PlantGroup*
    PlantGroup *pg = dynamic_cast<PlantGroup *>(component);
    if (pg)
    {
        groups.push_back(pg);
    }
}

/*!
 * @param component Plant* or PlantGroup* to be removed from the Inventory
 */
void Inventory::remove(InventoryComponent *component)
{
    // top-level groups first
    auto git = std::find(groups.begin(), groups.end(), component);
    if (git != groups.end())
    {
        delete *git;
        groups.erase(git);
        return;
    }

    // ask every group to remove it recursively
    for (auto g : groups)
        g->remove(component);
}

/*!
 * @return All Plant objects in the Inventory (both categorized and not)
 */
std::vector<Plant *> Inventory::getPlants()
{
    std::vector<Plant *> all;

    for (Plant *p : plants)
    {
        all.push_back(p);
    }

    for (PlantGroup *g : groups)
    {
        std::vector<Plant *> gp = g->getPlants();
        all.insert(all.end(), gp.begin(), gp.end());
    }

    return all;
}

/*!
 * @brief Changes the group a Plant is stored in based on a state change that has occurred
 *
 * @param plant Plant object to be moved
 * @param newState determines the group that the Plant object will be moved to
 */
void Inventory::movePlant(Plant *plant, std::string newState)
{
    // 1) remove from uncategorized list if present
    auto pit = std::find(plants.begin(), plants.end(), plant);
    if (pit != plants.end())
        plants.erase(pit);

    // 2) ask every top-level group to try the move
    for (auto g : groups)
        g->movePlant(plant, newState);
}
