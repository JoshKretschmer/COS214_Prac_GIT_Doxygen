#ifndef PEANUTCACTUS_H
#define PEANUTCACTUS_H

#include "Succulent.h"

class PeanutCactus : public Succulent {
public:
    PeanutCactus();
    ~PeanutCactus() override = default;
    Plant* clone() override;
    std::string getDetails() override;
    double getCost() override;
    void decorate(Plant* _plant) override;
};

#endif // PEANUTCACTUS_H