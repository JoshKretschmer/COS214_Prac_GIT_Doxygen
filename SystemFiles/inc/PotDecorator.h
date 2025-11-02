#ifndef POTDECORATOR_H
#define POTDECORATOR_H

#include "PlantDecorator.h"

/*!
 * @class PotDecorator
 *
 * @brief Concrete decorator class
 */
class PotDecorator : public PlantDecorator {
public:
    std::string getDetails();
    double getCost();
    PlantDecorator* clone();
};

#endif //POTDECORATOR_H
