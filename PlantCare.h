#ifndef PLANTCARE_H
#define PLANTCARE_H

#include <string>
using namespace std;

class Plant;

/*!
 * @class PlantCare
 *
 * @brief Parent class for different Plant care strategies
 */
class PlantCare {
public:
    PlantCare();
    virtual ~PlantCare();
    virtual bool executeCare() = 0;
    virtual string getCareType() = 0;
};

/*!
 * @class SunlightStrategy
 *
 * @brief Plant care strategy
 */
class SunlightStrategy : public PlantCare {
public:
    SunlightStrategy();
    bool executeCare();
    string getCareType();
};

/*!
 * @class WateringStrategy
 *
 * @brief Plant care strategy
 */
class WateringStrategy : public PlantCare {
public:
    WateringStrategy();
    bool executeCare();
    string getCareType();
};

/*!
 * @class FertilizingStrategy
 *
 * @brief Plant care strategy
 */
class FertilizingStrategy : public PlantCare {
public:
    FertilizingStrategy();
    bool executeCare();
    string getCareType();
};

/*!
 * @class CompositeCareStrategy
 *
 * @brief Combines all other Plant care strategies into one
 */
class CompositeCareStrategy : public PlantCare {
public:
    CompositeCareStrategy();
    bool executeCare();
    string getCareType();
};



#endif //PLANTCARE_H
