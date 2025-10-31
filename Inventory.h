#ifndef INVENTORY_H
#define INVENTORY_H

#include "InventoryComponent.h"
#include "InventoryIterator.h"
#include <vector>
#include <map>
#include <string>

class Plant;       
class PlantGroup;   

/*!
 * @class Inventory
 *
 * @brief Class for the main Inventory object that serves as storage for all sellable Plants in the system
 */
class Inventory : public InventoryComponent
{
private:
    std::vector<Plant*> plants;
    std::map<std::string, int> stockLevels;
    std::vector<PlantGroup*> groups;

public:
    Inventory();
    ~Inventory() override;

    void addPlant(Plant *plant);
    void removePlant(std::string plantId);
    void updateStock(std::string plantType, int quantity);
    int getStockLevel(std::string plantType);

    InventoryIterator *createIterator();

    int getPlantCount();
    void add(InventoryComponent *component) override;
    void remove(InventoryComponent *component) override;
    std::vector<Plant*> getPlants() override;
    void movePlant(Plant *plant, std::string newState) override;
};

#endif // INVENTORY_H
