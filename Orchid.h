#ifndef ORCHID_H
#define ORCHID_H

#include "Flower.h"

class Orchid : public Flower {
public:
    Orchid();
    ~Orchid() override = default;
    Plant* clone() override;
    std::string getDetails() override;
    double getCost() override;
    void decorate(Plant* _plant) override;
};

#endif // ORCHID_H