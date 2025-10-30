#ifndef INVENTORY_H
#define INVENTORY_H

#include "Plant.h"
#include "PlantState.h"
#include "Iterator.h"
#include <vector>
#include <string>
#include <map>
using namespace std;

class InventoryIterator;
class InventoryComponent;
class PlantState;

/*!
 * @class InventoryComponent
 *
 * @brief Parent class for object classes that can be stored in the Inventory, as well as the Inventory itself
 */
class InventoryComponent{//make own file
public:
    InventoryComponent();
    virtual ~InventoryComponent();

    virtual void add(InventoryComponent* component);
    virtual void remove(InventoryComponent* component);
    virtual vector<Plant*> getPlants();

    //virtual void notifyObservers();

    virtual void movePlant(Plant* plant, string newState);
};

/*!
 * @class PlantGroup
 *
 * @brief Subclass used to organize the Plant objects in Inventory into categories
 */
class PlantGroup : public InventoryComponent {//make own file
private:
    string groupName;
    vector<InventoryComponent*> children;
public:
    PlantGroup(string name);
    ~PlantGroup();

    void add(InventoryComponent* component);
    void remove(InventoryComponent* component);
    vector<Plant*> getPlants();
    void movePlant(Plant* plant, string newState);
};

/*!
 * @class Inventory
 *
 * @brief Class for the main Inventory object that serves as storage for all sellable Plants in the system
 */
class Inventory : public InventoryComponent {//keep in this file
private:
    vector<Plant*> plants;
    map<string, int> stockLevels;
    vector<PlantState*> states;
    vector<PlantGroup*> groups;
public:
    Inventory();
    ~Inventory();

    void addPlant(Plant* plant);
    void removePlant(string plantId);
    void updateStock(string plantType,int quantity);
    int getStockLevel(string plantType);

    InventoryIterator* createIterator();

    //void notifyObservers() override;

    int getPlantCount();
    void add(InventoryComponent* component) override;
    void remove(InventoryComponent* component) override;
    vector<Plant*> getPlants() override;
    void movePlant(Plant* plant, string newState) override;
};

#endif //INVENTORY_H