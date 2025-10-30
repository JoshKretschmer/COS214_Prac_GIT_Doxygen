#ifndef WRAPDECORATOR_H
#define WRAPDECORATOR_H

#include "PlantDecorator.h"

/*!
 * @class WrapDecorator
 *
 * @brief Concrete decorator class
 */
class WrapDecorator : public PlantDecorator {
public:
    string getDetails();
    double getCost();
    PlantDecorator* clone();
};

#endif //WRAPDECORATOR_H
