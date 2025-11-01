#ifndef CREATEFLOWER_H
#define CREATEFLOWER_H

#include "PlantFactory.h"

/*!
 * @class CreateFlower
 *
 * @brief Creator class for Orchid and Marigold classes
 */
class CreateFlower : public PlantFactory {
public:
    Plant* createPlant(std::string name);
};

#endif //CREATEFLOWER_H
