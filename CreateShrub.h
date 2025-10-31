#ifndef CREATESHRUB_H
#define CREATESHRUB_H

#include "PlantFactory.h"

/*!
 * @class CreateShrub
 *
 * @brief Creator class for BeeBlossom and HoneySuckle classes
 */
class CreateShrub : public PlantFactory {
public:
    Plant* createPlant(std::string name);
};

#endif //CREATESHRUB_H
