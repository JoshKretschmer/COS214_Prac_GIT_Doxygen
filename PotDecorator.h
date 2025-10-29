#ifndef POTDECORATOR_H
#define POTDECORATOR_H

#include "PlantDecorator.h"

class PotDecorator : public PlantDecorator {
public:
    PotDecorator() = default;
    ~PotDecorator() override = default;
    Plant* clone() override;
};

#endif // POTDECORATOR_H