#ifndef HONEYSUCKLE_H
#define HONEYSUCKLE_H

#include "Shrub.h"

/*!
 * @class HoneySuckle
 *
 * @brief public subclass of Shrub, specific kind of plant
 */
class HoneySuckle : public Shrub {
public:
    HoneySuckle();
    std::string getDetails();
    double getCost();
};

#endif //HONEYSUCKLE_H
