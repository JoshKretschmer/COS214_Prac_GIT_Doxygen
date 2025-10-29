#ifndef BEEBLOSSOM_H
#define BEEBLOSSOM_H

#include "Shrub.h"

class BeeBlossom : public Shrub {
public:
    BeeBlossom();
    ~BeeBlossom() override = default;
    Plant* clone() override;
    std::string getDetails() override;
    double getCost() override;
    void decorate(Plant* _plant) override;
};

#endif // BEEBLOSSOM_H