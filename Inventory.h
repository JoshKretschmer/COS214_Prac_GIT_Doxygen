#ifndef INVENTORY_H
#define INVENTORY_H

#include "Plant.h"
#include "PlantState.h"
#include "Iterator.h"
#include "Observer.h"
#include "NurseryMediator.h"
#include <vector>
#include <string>
#include <map>
using namespace std;

class InventoryIterator;
class NurseryMediator;
class PlantState;

class InventoryComponent : public Subject {
protected:
    NurseryMediator* mediator;
public:
    InventoryComponent(NurseryMediator* med = nullptr);
    virtual ~InventoryComponent();
    void setMediator(NurseryMediator* med);
    virtual void add(InventoryComponent* component);
    virtual void remove(InventoryComponent* component);
    virtual vector<Plant*> getPlants();
    virtual void notifyObservers();
    virtual void movePlant(Plant* plant, string newState);
};

class PlantGroup : public InventoryComponent {
private:
    string groupName;
    vector<InventoryComponent*> children;
public:
    PlantGroup(NurseryMediator* med = nullptr);
    ~PlantGroup();
    void add(InventoryComponent* component);
    void remove(InventoryComponent* component);
    vector<Plant*> getPlants();
    void movePlant(Plant* plant, string newState);
};

class Inventory : public InventoryComponent {
private:
    vector<Plant*> plants;
    map<string, int> stockLevels;
    vector<PlantState*> states;
    vector<PlantGroup*> groups;
public:
    Inventory(NurseryMediator* med);
    ~Inventory();
    void addPlant(Plant* plant);
    void removePlant(string plantId);
    void updateStock(string plantType,int quantity);
    int getStockLevel(string plantType);
    InventoryIterator* createIterator();
    void notifyObservers() override;
    void notifyMediator(string updateType, Plant& plant);
    int getPlantCount();
    void add(InventoryComponent* component) override;
    void remove(InventoryComponent* component) override;
    vector<Plant*> getPlants() override;
    void movePlant(Plant* plant, string newState) override;
};

#endif //INVENTORY_H
