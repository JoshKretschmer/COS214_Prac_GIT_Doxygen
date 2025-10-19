#ifndef PLANTSTATE_H
#define PLANTSTATE_H

#include "Plant.h"
#include <string>
using namespace std;

class PlantState {
    public:
        PlantState();
        virtual ~PlantState();
        void virtual handleCare(Plant& plant)=0;
        string virtual getStateName()=0;
};

class SeedingState : public PlantState {
    public:
        void handleCare(Plant& plant);
        string getStateName();
};

class GrowingState : public SeedingState {
    public:
        void handleCare(Plant& plant);
        string getStateName();
};

class MatureState : public SeedingState {
    public:
        void handleCare(Plant& plant);
        string getStateName();
};

class MoultState : public SeedingState {
    public:
        void handleCare(Plant& plant);
        string getStateName();
};



#endif //PLANTSTATE_H
