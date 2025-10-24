#include "PlantCare.h"

PlantCare::PlantCare()
{

}

//#############################################

SunlightStrategy::SunlightStrategy()
{

}

bool SunlightStrategy::executeCare()
{
    cout<<"\nProviding sunlight to the plant.\n";
    return true;
}

//#############################################

WateringStrategy::WateringStrategy()
{

}

bool WateringStrategy::executeCare()
{
    cout<<"\nWatering the plant.\n";
    return true;
}

//#############################################

FertilizingStrategy::FertilizingStrategy()
{

}

bool FertilizingStrategy::executeCare()
{
    cout<<"\nFertilizing the plant.\n";
    return true;
}

//#############################################

CompositeCareStrategy::CompositeCareStrategy()
{

}

bool CompositeCareStrategy::executeCare()
{
    cout<<"\nExecuting composite care strategy:\n";

    SunlightStrategy sunlight;
    WateringStrategy water;
    FertilizingStrategy fertilize;

    sunlight.executeCare();
    water.executeCare();
    fertilize.executeCare();
    return true;
}

PlantCare::~PlantCare() {}  
SunlightStrategy::~SunlightStrategy() {}
WateringStrategy::~WateringStrategy() {}
FertilizingStrategy::~FertilizingStrategy() {}
CompositeCareStrategy::~CompositeCareStrategy() {}