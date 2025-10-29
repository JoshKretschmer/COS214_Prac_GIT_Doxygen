#ifndef ARRANGEMENTDECORATOR_H
#define ARRANGEMENTDECORATOR_H

#include "PlantDecorator.h"

class ArrangementDecorator : public PlantDecorator {
public:
    ArrangementDecorator() = default;
    ~ArrangementDecorator() override = default;
    Plant* clone() override;
};

#endif // ARRANGEMENTDECORATOR_H