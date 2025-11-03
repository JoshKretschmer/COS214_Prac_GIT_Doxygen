#ifndef HOUSELEEK_H
#define HOUSELEEK_H

#include "Succulent.h"

/*!
 * @class HouseLeek
 *
 * @brief public subclass of Succulent, specific kind of plant
 */
class HouseLeek : public Succulent
{
public:
    HouseLeek();
    std::string getDetails();
    double getCost();
};

#endif // HOUSELEEK_H
