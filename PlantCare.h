#ifndef PLANTCARE_H
#define PLANTCARE_H

#include "libraries.h"
#include "Plant.h"

class Plant;

class PlantCare
{
    public:
        PlantCare();
        virtual ~PlantCare();
        virtual bool executeCare()=0;
        virtual string getStrategyName()=0;
};

class SunlightStrategy : public PlantCare
{
    public:
        SunlightStrategy();
        virtual ~SunlightStrategy();
        virtual bool executeCare() override;
        virtual string getStrategyName() override;
};

class WateringStrategy : public PlantCare
{
    public:
        WateringStrategy();
        ~WateringStrategy();
        virtual bool executeCare() override;
        virtual string getStrategyName() override;
};

class FertilizingStrategy : public PlantCare
{
    public:
        FertilizingStrategy();
        ~FertilizingStrategy();
        virtual bool executeCare() override;
        virtual string getStrategyName() override;
};



#endif //PLANTCARE_H