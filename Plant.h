#ifndef PLANT_H
#define PLANT_H

#include "libraries.h"
#include "PlantCare.h"
#include "PlantState.h"
#include <string>

class PlantState;
class PlantCare;

class Plant {
protected:
    std::string id;
    std::string group;
    std::string plant_type;
    double plant_price = 0.0;
    int health = 0;
    bool fertilized = false;
    bool watered = false;
    bool sunLit = false;
    static int instanceCount;
    PlantState* currState = nullptr;
    PlantCare* careRegime = nullptr;

    bool needsCare();
    void incrementHealth(int num);
    int handleCare();

public:
    Plant();
    virtual ~Plant();

    virtual std::string getDetails() = 0;
    virtual double getCost() = 0;
    virtual Plant* clone() = 0;
    virtual void decorate(Plant* _plant) = 0;

    std::string getPlantID() const { return id; }
    std::string getPlantGroup() const { return group; }
    int getPlantHealth() const { return health; }
    std::string getPlantType() const { return plant_type; }
    std::string getState();
    std::string getCareRegime();

    void changeState(PlantState* _state);
    void nuturePlant();
};

#endif // PLANT_H