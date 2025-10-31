#ifndef COMPOSITESTRATEGY_H
#define COMPOSITESTRATEGY_H

#include "PlantCare.h"

class CompositeCareStrategy : public PlantCare
{
public:
    CompositeCareStrategy();
    bool executeCare();
    std::string getCareType();
    virtual PlantCare *clone() const override;
};

#endif // COMPOSITESTRATEGY_H
