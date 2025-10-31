#ifndef SUNLIGHTSTRATEGY_H
#define SUNLIGHTSTRATEGY_H

#include "PlantCare.h"

class SunlightStrategy : public PlantCare {
public:
    SunlightStrategy();
    bool executeCare();
    std::string getCareType();
};

#endif //SUNLIGHTSTRATEGY_H
