#ifndef PLANTCARE_H
#define PLANTCARE_H

/*!
 * @headerfile PlantCare.h
 */
#include "libraries.h"
#include "Plant.h"

class Plant;

/*!
 * @class PlantCare
 *
 * @brief Parent class for strategies that manage the various plant care tasks
 */
class PlantCare
{
    public:
        PlantCare();
        virtual ~PlantCare();
        virtual bool executeCare()=0;
        virtual string getStrategyName()=0;
};

/*!
 * @class SunlightStrategy
 *
 * @brief Strategy for providing sunlight care to a Plant object
 */
class SunlightStrategy : public PlantCare
{
    public:
        SunlightStrategy();
        virtual ~SunlightStrategy();
        virtual bool executeCare() override;
        virtual string getStrategyName() override;
};

/*!
 * @class WateringStrategy
 *
 * @brief Strategy for providing water care to a Plant object
 */
class WateringStrategy : public PlantCare
{
    public:
        WateringStrategy();
        ~WateringStrategy();
        virtual bool executeCare() override;
        virtual string getStrategyName() override;
};

/*!
 * @class FertilizingStrategy
 *
 * @brief Strategy for providing fertilizer care to a Plant object
 */
class FertilizingStrategy : public PlantCare
{
    public:
        FertilizingStrategy();
        ~FertilizingStrategy();
        virtual bool executeCare() override;
        virtual string getStrategyName() override;
};



#endif //PLANTCARE_H