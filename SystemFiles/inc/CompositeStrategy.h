#ifndef COMPOSITESTRATEGY_H
#define COMPOSITESTRATEGY_H

#include "PlantCare.h"

/*!
 * @class CompositeCareStrategy
 *
 * @brief Concrete PlantCare Strategy class. Combines all other PlantCare strategies into one
 */
class CompositeCareStrategy : public PlantCare
{
public:
    CompositeCareStrategy();
    bool executeCare();
    std::string getCareType();
    virtual PlantCare *clone() const override;
};

#endif // COMPOSITESTRATEGY_H
