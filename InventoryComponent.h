#ifndef INVENTORYCOMPONENT_H
#define INVENTORYCOMPONENT_H

#include "Plant.h"
#include "PlantState.h"
#include "Iterator.h"
#include <vector>
#include <string>
#include <map>
using namespace std;

class InventoryComponent{
public:
    InventoryComponent();
    virtual ~InventoryComponent();

    virtual void add(InventoryComponent* component);
    virtual void remove(InventoryComponent* component);
    virtual vector<Plant*> getPlants();

    //virtual void notifyObservers();

    virtual void movePlant(Plant* plant, string newState);
};

#endif //INVENTORYCOMPONENT_H
