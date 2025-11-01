#ifndef PLANT_H
#define PLANT_H

#include <string>
#include <vector>
#include "InventoryComponent.h"

class PlantCare;
class PlantState;

/*!
 * @class Plant
 *
 * @brief Main Plant class – **leaf** of the Composite pattern
 *
 *  Parent class for different types of plants.
 *  Product in Factory Method, ConcreteComponent in Decorator, Context for State
 */

class Plant : public InventoryComponent
{
protected:
    std::string id;
    std::string type;
    double price;
    PlantState *currState;
    PlantCare *careRegime;
    int health;

public:
    Plant();
    virtual ~Plant() override;
    virtual std::string getDetails() = 0;
    virtual double getCost() = 0;

    void changeState(PlantState *newState);
    bool needsCare();
    int getHealth() const { return health; }
    std::string getID() const { return id; }
    std::string getType() const { return type; }
    void incrementHealth(int num);
    std::string getState();
    Plant *clone();

    PlantCare *getCareRegime() const { return careRegime; }
    void setCareRegime(PlantCare *care) { careRegime = care; }
    void setHealth(int h) { health = h; }

    void add(InventoryComponent *) override;
    void remove(InventoryComponent *) override;
    std::vector<Plant *> getPlants() override;
    void movePlant(Plant *plant, std::string newState) override;
};

#endif // PLANT_H