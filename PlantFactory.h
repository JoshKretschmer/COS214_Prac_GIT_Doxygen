/*!
*  @headerfile PlantFactory.h
 *
 *  @brief Contains class definitions for creator classes of Plant objects
 *
 *  Patterns: Factory Method
 */

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
    virtual Plant* createPlant(string name)=0;
};

/*!
 * @class CreateSucculent
 *
 * @brief Creator class for PeanutCactus and HouseLeek classes
 */
class CreateSucculent : public PlantFactory {
public:
    Plant* createPlant(string name);
};

/*!
 * @class CreateFlower
 *
 * @brief Creator class for Orchid and Marigold classes
 */
class CreateFlower : public PlantFactory {
public:
    Plant* createPlant(string name);
};

/*!
 * @class CreateShrub
 *
 * @brief Creator class for BeeBlossom and HoneySuckle classes
 */
class CreateShrub : public PlantFactory {
public:
    Plant* createPlant(string name);
};

#endif //PLANTFACTORY_H