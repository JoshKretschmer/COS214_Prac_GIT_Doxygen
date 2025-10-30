/*!
 * @class Succulent
 *
 * @brief public subclass of Plant, category of plants
 */
//Produc participant in Factory Method
#ifndef SUCCULENT_H
#define SUCCULENT_H

#include "Plant.h"
class Succulent : public Plant {
    public:
        Succulent();
        string virtual getDetails()=0;
        double virtual getCost()=0;
};

#endif