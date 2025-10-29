#ifndef SHRUB_H
#define SHRUB_H

#include "Plant.h"

class Shrub : public Plant {
public:
    Shrub();
    ~Shrub() override = default;
};

#endif // SHRUB_H