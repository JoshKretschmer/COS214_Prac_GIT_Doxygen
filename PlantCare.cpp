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
    cout<<"\nProviding sunlight to the plant...\n";
    return true;
}

string SunlightStrategy::getStrategyName()
{
    return toUpperCase("sunlight");
}

//#############################################

WateringStrategy::WateringStrategy()
{

}

bool WateringStrategy::executeCare()
{
    cout<<"\nWatering the plant...\n";
    return true;
}

string WateringStrategy::getStrategyName()
{
    return toUpperCase("watering");
}
//#############################################

FertilizingStrategy::FertilizingStrategy()
{

}

bool FertilizingStrategy::executeCare()
{
    cout<<"\nFertilizing the plant...\n";
    return true;
}

string FertilizingStrategy::getStrategyName()
{
    return toUpperCase("fertilizing");
}

PlantCare::~PlantCare() {}  
SunlightStrategy::~SunlightStrategy() {}
WateringStrategy::~WateringStrategy() {}
FertilizingStrategy::~FertilizingStrategy() {}
