#ifndef INVENTORYCOMPONENT_H
#define INVENTORYCOMPONENT_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

#include "PlantState.h"
#include "Iterator.h"
#include "Plant.h"

/*!
 * @class InventoryComponent
 *
 * @brief Parent class for object classes that can be stored in the Inventory, as well as the Inventory itself
 */
class InventoryComponent
{
public:
    InventoryComponent();
    virtual ~InventoryComponent();

    virtual void add(InventoryComponent *component);
    virtual void remove(InventoryComponent *component);
    virtual vector<Plant *> getPlants() = 0;

    virtual void movePlant(Plant *plant, std::string newState);
};

#endif // INVENTORYCOMPONENT_H
