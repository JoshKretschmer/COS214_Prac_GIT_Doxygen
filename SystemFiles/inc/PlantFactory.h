#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include "Plant.h"

/*!
 * @class PlantFactory
 *
 * @brief Abstract parent factory for specific plant factories
 */
class PlantFactory {
public:
    PlantFactory();
    virtual ~PlantFactory();
    virtual Plant* createPlant( std::string name)=0;
};

#endif //PLANTFACTORY_H
