#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

#include "libraries.h"
#include "Plant.h"
#include <string>

class PlantDecorator : public Plant {
protected:
    Plant* wrappedPlant = nullptr;
    double decorator_price = 0.0;
    std::string decorator_type;

public:
    PlantDecorator() = default;
    virtual ~PlantDecorator() override;

    std::string getDetails() override;
    double getCost() override;
    void decorate(Plant* _plant) override;
};

#endif // PLANTDECORATOR_H