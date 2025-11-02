#ifndef FLOWER_H
#define FLOWER_H

#include "Plant.h"

/*!
 * @class Flower
 *
 * @brief public subclass of Plant, category of plants
 */
class Flower : public Plant {
public:
    Flower();
    std::string virtual getDetails()=0;
    double virtual getCost()=0;
};



#endif //FLOWER_H
