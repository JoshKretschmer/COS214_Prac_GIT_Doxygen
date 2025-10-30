#ifndef MARIGOLD_H
#define MARIGOLD_H

#include "Flower.h"

/*!
 * @class Marigold
 *
 * @brief public subclass of Flower, specific kind of plant
 */
class Marigold : public Flower {
public:
    Marigold();
    string getDetails();
    double getCost();
};

#endif //MARIGOLD_H
