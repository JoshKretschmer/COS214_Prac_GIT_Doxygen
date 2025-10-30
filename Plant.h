#ifndef PLANT_H
#define PLANT_H

/*!
 *@headerfile Plant.h
 *
 *@brief Class hierarchy for main plant product
 */

#include "PlantCare.h"
#include "PlantState.h"
//#include "Inventory.h"
#include <string>
#include <vector>
#include <iostream>

class InventoryComponent;

using namespace std;


/*!
 * @class Plant
 *
 * @Brief Main Plant class
 *
 *  Parent class for different types of plants.
 *  Product in Factory Method, ConcreteComponent in Decorator, Context for State
 *
 */
class Plant{
protected:
    string id;//
    string type;
    double price;
    PlantState* currState;//
    PlantCare* careRegime;
    int health;
public:
    Plant();
    virtual ~Plant();
    string virtual getDetails()=0;
    double virtual getCost()=0;
    void changeState(PlantState* newState);
    bool needsCare();
    int getHealth() { return health; };
    string getID() { return id; };
    string getType() { return type; };
    void incrementHealth(int num);
    string getState();
    Plant* clone();
};

#endif //PLANT_H
