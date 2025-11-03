#ifndef PLANTGROUP_H
#define PLANTGROUP_H

#include "InventoryComponent.h"
#include <vector>

class Plant;

/*!
 * @class PlantGroup
 *
 * @brief Subclass used to organize the Plant objects in Inventory into categories
 */
class PlantGroup : public InventoryComponent
{
private:
    std::string groupName;
    std::vector<InventoryComponent *> children; // holds Plant* or PlantGroup*

public:
    PlantGroup(std::string name);
    ~PlantGroup() override;

    void add(InventoryComponent *component) override;
    void remove(InventoryComponent *component) override;
    std::vector<Plant *> getPlants() override;
    void movePlant(Plant *plant, std::string newState) override;

    const std::string &getName() const { return groupName; }
};

#endif // PLANTGROUP_H