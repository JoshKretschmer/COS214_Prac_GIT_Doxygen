#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

/*!
 * @headerfile PlantFactory.h
 */
#include "libraries.h"
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
    Plant* createPlant(string name) override;
};

/*!
 * @class CreateFlower
 *
 * @brief Creator class for Orchid and Marigold classes
 */
class CreateFlower : public PlantFactory {
public:
    Plant* createPlant(string name) override;
};

/*!
 * @class CreateShrub
 *
 * @brief Creator class for BeeBlossom and HoneySuckle classes
 */
class CreateShrub : public PlantFactory {
public:
    Plant* createPlant(string name) override;
};

#endif //PLANTFACTORY_H