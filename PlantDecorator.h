/*!
*  @headerfile PlantDecorator.h
 *
 *  @brief Contains class definitions for PlantDecorator and its various subclasses
 *
 *  Patterns: Decorator
 */

#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

#include "Plant.h"
#include <string>
using namespace std;

/*!
 * @class PlantDecorator
 *
 * @brief Abstract interface class for various decorator subclasses
 */
class PlantDecorator : public Plant{
private:
    Plant* wrappedPlant;
protected:
    Plant* getWrapped() {return wrappedPlant;};
public:
    PlantDecorator();
    ~PlantDecorator();
    virtual string getDetails() = 0;
    virtual double getCost() = 0;
    void setWrapped(Plant* wrappedPlant);
    virtual PlantDecorator* clone();
};

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

/*!
 * @class PotDecorator
 *
 * @brief Concrete decorator class
 */
class PotDecorator : public PlantDecorator {
public:
    string getDetails();
    double getCost();
    PlantDecorator* clone();
};

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

#endif //PLANTDECORATOR_H