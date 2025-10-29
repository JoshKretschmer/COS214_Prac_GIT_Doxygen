#ifndef PLANTSTATE_H
#define PLANTSTATE_H

#include "libraries.h"
#include "Plant.h"


class Plant;

class PlantState
{
    public:
        PlantState();
        virtual ~PlantState();
        virtual int handleCare(Plant* plant)=0;
        virtual string getStateName()=0;
};

class SeedingState : public PlantState {
    public:
        SeedingState();
        virtual int handleCare(Plant* plant) override;
        virtual string getStateName() override;
};

class GrowingState : public SeedingState {
    public:
        GrowingState();
        virtual int handleCare(Plant* plant) override;
        virtual string getStateName() override;
};

class MatureState : public SeedingState {
    public:
        MatureState();
        virtual int handleCare(Plant* plant) override;
        virtual string getStateName() override;
};

class MoultState : public SeedingState {
    public:
        MoultState();
        virtual int handleCare(Plant* plant) override;
        virtual string getStateName() override;
};

class DeadState : public PlantState {
public:
    virtual int handleCare(Plant* plant) override;
    virtual string getStateName() override;
};



#endif //PLANTSTATE_H