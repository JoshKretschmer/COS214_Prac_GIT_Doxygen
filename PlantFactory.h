#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include "Plant.h"

class PlantFactory {
    public:
        PlantFactory();
        virtual ~PlantFactory();
        virtual Plant* createPlant()=0;
};

class CreateSucculent : public PlantFactory {
    public:
        CreateSucculent();
        Plant* createPlant();
};

class CreateFlower : public PlantFactory {
    public:
        CreateFlower();
        Plant* createPlant();
};

class CreateShrub : public PlantFactory {
    public:
        CreateShrub();
        Plant* createPlant();
};

#endif //PLANTFACTORY_H
