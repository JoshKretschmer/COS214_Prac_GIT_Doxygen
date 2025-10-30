#ifndef SUCCULENT_H
#define SUCCULENT_H

#include "Plant.h"

class Succulent : public Plant {
public:
    Succulent();
    string virtual getDetails()=0;
    double virtual getCost()=0;
};

#endif //SUCCULENT_H
