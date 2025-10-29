#ifndef CREATEFLOWER_H
#define CREATEFLOWER_H

#include "PlantFactory.h"

class CreateFlower : public PlantFactory {
public:
    Plant* createPlant(const std::string& name) override;
};

#endif // CREATEFLOWER_H