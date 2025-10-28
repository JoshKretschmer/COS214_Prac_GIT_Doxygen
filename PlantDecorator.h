#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

/*!
 * @headerfile PlantDecorator.h
 */
#include "libraries.h"
#include "Plant.h"


/*!
 * @class PlantDecorator
 *
 * @brief Abstract interface class for various decorator subclasses
 */
class PlantDecorator : public Plant
{
protected:
    Plant * wrappedPlant;

    double decorator_price;
    string decorator_type;

    

public:
    PlantDecorator();
    virtual ~PlantDecorator();

    virtual string getDetails() override;
    virtual double getCost() override;
    virtual void decorate(Plant* _plant) override;
};

/*!
 * @class ArrangementDecorator
 *
 * @brief Concrete decorator class
 */
class ArrangementDecorator : public PlantDecorator
{
public:
    ArrangementDecorator();
    ~ArrangementDecorator();
    virtual Plant *clone() override;

};

/*!
 * @class PotDecorator
 *
 * @brief Concrete decorator class
 */
class PotDecorator : public PlantDecorator
{
public:
    PotDecorator();
    ~PotDecorator();
    virtual Plant *clone() override;
};

/*!
 * @class WrapDecorator
 *
 * @brief Concrete decorator class
 */
class WrapDecorator : public PlantDecorator
{
public:
    WrapDecorator();
    ~WrapDecorator();
    virtual Plant *clone() override;
};

#endif // PLANTDECORATOR_H