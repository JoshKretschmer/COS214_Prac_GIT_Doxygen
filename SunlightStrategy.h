#ifndef SUNLIGHTSTRATEGY_H
#define SUNLIGHTSTRATEGY_H

#include "PlantCare.h"

class SunlightStrategy : public PlantCare {
public:
    SunlightStrategy() = default;
    ~SunlightStrategy() override = default;
    bool executeCare() override;
    std::string getStrategyName() override;
};

#endif // SUNLIGHTSTRATEGY_H