#ifndef BEEBLOSSOM_H
#define BEEBLOSSOM_H

#include "Shrub.h"

/*!
 * @class BeeBlossom
 *
 * @brief public subclass of Shrub, specific kind of plant
 */
class BeeBlossom : public Shrub
{
public:
    BeeBlossom();
    std::string getDetails();
    double getCost();
};

#endif // BEEBLOSSOM_H
