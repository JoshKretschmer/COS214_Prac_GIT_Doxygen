#ifndef PLANTSTATE_H
#define PLANTSTATE_H

#include "libraries.h"
#include <string>

class Plant;

class PlantState {
public:
    PlantState() = default;
    virtual ~PlantState() = default;
    virtual int handleCare(Plant* plant) = 0;
    virtual std::string getStateName() = 0;
};

#endif // PLANTSTATE_H