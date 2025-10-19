#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

#include "Plant.h"
#include <string>
#include <vector>
using namespace std;

class PlantDecorator : public Plant{
private:
    Plant* wrappedPlant;
protected:
    Plant* getWrapped() {return wrappedPlant;};
public:
    PlantDecorator();
    ~PlantDecorator();
    virtual string getDetails() = 0;
    virtual double getCost() = 0;
    void setWrapped(Plant* wrappedPlant);
};

class ArrangementDecorator : public PlantDecorator {
public:
    string getDetails();
    double getCost();
};

class PotDecorator : public PlantDecorator {
public:
    string getDetails();
    double getCost();
};

class WrapDecorator : public PlantDecorator {
public:
    string getDetails();
    double getCost();
};

#endif //PLANTDECORATOR_H
