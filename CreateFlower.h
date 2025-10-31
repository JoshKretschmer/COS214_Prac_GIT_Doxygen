#ifndef CREATEFLOWER_H
#define CREATEFLOWER_H

#include "PlantFactory.h"

class CreateFlower : public PlantFactory {
public:
    Plant* createPlant(std::string name);
};

#endif //CREATEFLOWER_H
