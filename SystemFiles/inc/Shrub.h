#ifndef SHRUB_H
#define SHRUB_H

#include "Plant.h"

/*!
 * @class Shrub
 *
 * @brief public subclass of Plant, category of plants
 */
class Shrub : public Plant
{
public:
    Shrub();
    std::string virtual getDetails() = 0;
    double virtual getCost() = 0;
};

#endif // SHRUB_H