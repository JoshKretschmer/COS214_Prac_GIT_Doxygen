#ifndef WRAPDECORATOR_H
#define WRAPDECORATOR_H

#include "PlantDecorator.h"

class WrapDecorator : public PlantDecorator {
public:
    WrapDecorator() = default;
    ~WrapDecorator() override = default;
    Plant* clone() override;
};

#endif // WRAPDECORATOR_H