#ifndef PLANTCARE_H
#define PLANTCARE_H

#include "libraries.h"
#include <string>

class Plant;

class PlantCare {
public:
    PlantCare() = default;
    virtual ~PlantCare() = default;
    virtual bool executeCare() = 0;
    virtual std::string getStrategyName() = 0;
};

#endif // PLANTCARE_H