#ifndef CREATESUCCULENT_H
#define CREATESUCCULENT_H

#include "PlantFactory.h"

/*!
 * @class CreateSucculent
 *
 * @brief Creator class for PeanutCactus and HouseLeek classes
 */
class CreateSucculent : public PlantFactory {
public:
    Plant* createPlant(std::string name);
};

#endif //CREATESUCCULENT_H
