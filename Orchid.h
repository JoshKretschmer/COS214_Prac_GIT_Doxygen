#ifndef ORCHID_H
#define ORCHID_H

#include "Flower.h"

class Orchid : public Flower {
public:
    Orchid();
    std::string getDetails();
    double getCost();
};

#endif //ORCHID_H
