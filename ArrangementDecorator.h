#ifndef ARRANGEMENTDECORATOR_H
#define ARRANGEMENTDECORATOR_H

#include "PlantDecorator.h"

/*!
 * @class ArrangementDecorator
 *
 * @brief Concrete decorator class
 */
class ArrangementDecorator : public PlantDecorator {
public:
    string getDetails();
    double getCost();
    PlantDecorator* clone();
};

#endif //ARRANGEMENTDECORATOR_H
