#ifndef CREATESUCCULENT_H
#define CREATESUCCULENT_H

#include "PlantFactory.h"

class CreateSucculent : public PlantFactory {
public:
    Plant* createPlant(const std::string& name) override;
};

#endif // CREATESUCCULENT_H