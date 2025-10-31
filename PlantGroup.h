#ifndef PLANTGROUP_H
#define PLANTGROUP_H

#include "InventoryComponent.h"
#include "Plant.h"
#include <vector>

/*!
 * @class PlantGroup
 *
 * @brief Subclass used to organize the Plant objects in Inventory into categories
 */
class PlantGroup : public InventoryComponent
{
private:
    std::string groupName;
    vector<InventoryComponent *> children;

public:
    PlantGroup(std::string name);
    ~PlantGroup();

    void add(InventoryComponent *component);
    void remove(InventoryComponent *component);
    vector<Plant *> getPlants();
    void movePlant(Plant *plant, std::string newState);
};

#endif // PLANTGROUP_H
