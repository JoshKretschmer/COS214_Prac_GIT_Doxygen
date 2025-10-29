#ifndef FLOWER_H
#define FLOWER_H

#include "Plant.h"

class Flower : public Plant {
public:
    Flower();
    ~Flower() override = default;
};

#endif // FLOWER_H