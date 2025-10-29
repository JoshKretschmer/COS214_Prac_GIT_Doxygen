#ifndef HONEYSUCKLE_H
#define HONEYSUCKLE_H

#include "Shrub.h"

class HoneySuckle : public Shrub {
public:
    HoneySuckle();
    ~HoneySuckle() override = default;
    Plant* clone() override;
    std::string getDetails() override;
    double getCost() override;
    void decorate(Plant* _plant) override;
};

#endif // HONEYSUCKLE_H