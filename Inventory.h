#ifndef INVENTORY_H
#define INVENTORY_H

#include "InventoryComponent.h"
#include "PlantGroup.h"

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
