#ifndef SUCCULENT_H
#define SUCCULENT_H

#include "Plant.h"

class Succulent : public Plant {
public:
    Succulent();
    ~Succulent() override = default;
};

#endif // SUCCULENT_H