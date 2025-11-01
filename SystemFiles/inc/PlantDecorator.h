#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

#include "Plant.h"
#include <string>

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
    virtual std::string getDetails() = 0;
    virtual double getCost() = 0;
    void setWrapped(Plant* wrappedPlant);
    // virtual PlantDecorator* clone();
};

#endif //PLANTDECORATOR_H
