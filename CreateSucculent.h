#ifndef CREATESUCCULENT_H
#define CREATESUCCULENT_H

#include "PlantFactory.h"

class CreateSucculent : public PlantFactory {
public:
    Plant* createPlant(string name);
};

#endif //CREATESUCCULENT_H
