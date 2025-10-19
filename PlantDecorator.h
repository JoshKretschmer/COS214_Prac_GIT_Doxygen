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
        Plant* getWrapped;
    public:
        PlantDecorator();
        virtual ~PlantDecorator();
        virtual string getDetails();
        virtual double getCost();
        void setWrapped(Plant* wrappedPlant);
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
