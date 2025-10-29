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
    virtual Plant* createPlant(string name) override;
};

class CreateFlower : public PlantFactory {
public:
    virtual Plant* createPlant(string name) override;
};

class CreateShrub : public PlantFactory {
public:
    virtual Plant* createPlant(string name) override;
};

#endif //PLANTFACTORY_H