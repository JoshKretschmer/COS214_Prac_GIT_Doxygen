#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include "libraries.h"
#include "Plant.h"


class PlantFactory {
public:
    PlantFactory();
    virtual ~PlantFactory();
    virtual Plant* createPlant(string name)=0;
};

class CreateSucculent : public PlantFactory {
public:
    Plant* createPlant(string name);
};

class CreateFlower : public PlantFactory {
public:
    Plant* createPlant(string name);
};

class CreateShrub : public PlantFactory {
public:
    Plant* createPlant(string name);
};

#endif //PLANTFACTORY_H