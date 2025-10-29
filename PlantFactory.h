#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include "libraries.h"
#include <string>

class Plant;

class PlantFactory {
public:
    PlantFactory() = default;
    virtual ~PlantFactory() = default;
    virtual Plant* createPlant(const std::string& name) = 0;
};

#endif // PLANTFACTORY_H