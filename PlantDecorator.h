#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

#include "Plant.h"
#include <string>
using namespace std;

class ConcretePlant : public Plant {
    public:
        ConcretePlant();
        string getDetails();
        double getCost();
};

class PlantDecorator : public Plant{
    private:
        Plant* wrappedPlant;
    public:
        PlantDecorator();
        virtual ~PlantDecorator();
        virtual string getDetails();
        virtual double getCost();
};

class ArrangementDecorator : public PlantDecorator {
    public:
        ArrangementDecorator();
        string getDetails();
        double getCost();
};

class PotDecorator : public PlantDecorator {
    public:
        PotDecorator();
        string getDetails();
        double getCost();
};

class WrapDecorator : public PlantDecorator {
    public:
        WrapDecorator();
        string getDetails();
        double getCost();
};

#endif //PLANTDECORATOR_H
