#ifndef PLANTCARE_H
#define PLANTCARE_H

#include "libraries.h"

class Plant;

class PlantCare
{
    public:
        PlantCare();
        virtual ~PlantCare();
        virtual bool executeCare()=0;
};

class SunlightStrategy : public PlantCare
{
    public:
        SunlightStrategy();
        virtual ~SunlightStrategy();
        virtual bool executeCare() override;
};

class WateringStrategy : public PlantCare
{
    public:
        WateringStrategy();
        ~WateringStrategy();
        virtual bool executeCare() override;
};

class FertilizingStrategy : public PlantCare
{
    public:
        FertilizingStrategy();
        ~FertilizingStrategy();
        virtual bool executeCare() override;
};

class CompositeCareStrategy : public PlantCare
{
    public:
        CompositeCareStrategy();
        virtual ~CompositeCareStrategy();
        virtual bool executeCare() override;
};



#endif //PLANTCARE_H