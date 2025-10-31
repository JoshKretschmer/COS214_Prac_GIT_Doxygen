#ifndef PLANT_H
#define PLANT_H

/*!
 *@headerfile Plant.h
 *
 *@brief Class hierarchy for main plant product
 */

#include <string>
#include <vector>

#include "PlantCare.h"
#include "PlantState.h"

class InventoryComponent;

/*!
 * @class Plant
 *
 * @Brief Main Plant class
 *
 *  Parent class for different types of plants.
 *  Product in Factory Method, ConcreteComponent in Decorator, Context for State
 *
 */
class Plant
{
protected:
    std::string id; //
    std::string type;
    double price;
    PlantState *currState; //
    PlantCare *careRegime;
    int health;

public:
    Plant();
    virtual ~Plant();
    std::string virtual getDetails() = 0;
    double virtual getCost() = 0;
    void changeState(PlantState *newState);
    bool needsCare();
    int getHealth() { return health; };
    std::string getID() { return id; };
    std::string getType() { return type; };
    void incrementHealth(int num);
    std::string getState();
    Plant *clone();
};

#endif // PLANT_H
