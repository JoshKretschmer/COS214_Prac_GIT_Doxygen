#ifndef CREATESHRUB_H
#define CREATESHRUB_H

#include "PlantFactory.h"

class CreateShrub : public PlantFactory {
public:
    Plant* createPlant(const std::string& name) override;
};

#endif // CREATESHRUB_H