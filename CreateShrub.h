#ifndef CREATESHRUB_H
#define CREATESHRUB_H

#include "PlantFactory.h"

class CreateShrub : public PlantFactory {
public:
    Plant* createPlant(string name);
};

#endif //CREATESHRUB_H
