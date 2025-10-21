#ifndef PLANTSTATE_H
#define PLANTSTATE_H

#include "Plant.h"
#include <string>
using namespace std;

class Plant;

class PlantState {
    public:
        PlantState();
        virtual ~PlantState();
        void virtual handleCare(Plant& plant)=0;
        string virtual getStateName()=0;
};

class SeedingState : public PlantState {
    public:
        SeedingState();
        void handleCare(Plant& plant);
        string getStateName();
};

class GrowingState : public SeedingState {
    public:
        GrowingState();
        void handleCare(Plant& plant);
        string getStateName();
};

class MatureState : public SeedingState {
    public:
        MatureState();
        void handleCare(Plant& plant);
        string getStateName();
};

class MoultState : public SeedingState {
    public:
        MoultState();
        void handleCare(Plant& plant);
        string getStateName();
};



#endif //PLANTSTATE_H
