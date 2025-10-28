#include "PlantCare.h"

/*!
 * @brief Basic constructor function
 */
PlantCare::PlantCare()
{

}

//#############################################

/*!
 * @brief Basic constructor function
 */
SunlightStrategy::SunlightStrategy()
{

}

/*!
 * @brief Simulates Plant care actions
 *
 * @return true
 */
bool SunlightStrategy::executeCare()
{
    cout<<"\nProviding sunlight to the plant...\n";
    return true;
}

/*!
 *
 * @return name of the specific strategy: "sunlight"
 */
string SunlightStrategy::getStrategyName()
{
    return toUpperCase("sunlight");
}

//#############################################

/*!
 * @brief Basic constructor function
 */
WateringStrategy::WateringStrategy()
{

}

/*!
 * @brief Simulates Plant care actions
 *
 * @return true
 */
bool WateringStrategy::executeCare()
{
    cout<<"\nWatering the plant...\n";
    return true;
}

/*!
 *
 * @return name of the specific strategy: "watering"
 */
string WateringStrategy::getStrategyName()
{
    return toUpperCase("watering");
}
//#############################################

/*!
 * @brief Basic constructor function
 */
FertilizingStrategy::FertilizingStrategy()
{

}

/*!
 * @brief Simulates Plant care actions
 *
 * @return true
 */
bool FertilizingStrategy::executeCare()
{
    cout<<"\nFertilizing the plant...\n";
    return true;
}

/*!
 *
 * @return name of the specific strategy: "fertilizing"
 */
string FertilizingStrategy::getStrategyName()
{
    return toUpperCase("fertilizing");
}

/*!
 * @brief Basic destructor functions for all classes
 */
PlantCare::~PlantCare() {}
SunlightStrategy::~SunlightStrategy() {}
WateringStrategy::~WateringStrategy() {}
FertilizingStrategy::~FertilizingStrategy() {}
