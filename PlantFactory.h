#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include "Plant.h"

class PlantFactory {
public:
    PlantFactory();
    virtual ~PlantFactory();
    virtual Plant* createPlant( std::string name)=0;
};

#endif //PLANTFACTORY_H
