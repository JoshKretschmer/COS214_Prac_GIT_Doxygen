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

class Plant;
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

    virtual void add(InventoryComponent *component) = 0;
    virtual void remove(InventoryComponent *component) = 0;
    virtual vector<Plant *> getPlants() = 0;
    virtual void movePlant(Plant *plant, std::string newState) = 0;
};

#endif // INVENTORYCOMPONENT_H
