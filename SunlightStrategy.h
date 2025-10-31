#ifndef SUNLIGHTSTRATEGY_H
#define SUNLIGHTSTRATEGY_H

#include "PlantCare.h"

class SunlightStrategy : public PlantCare
{
public:
    SunlightStrategy();
    bool executeCare();
    std::string getCareType();
    virtual PlantCare *clone() const override;
};

#endif // SUNLIGHTSTRATEGY_H
