#ifndef MARIGOLD_H
#define MARIGOLD_H

#include "Flower.h"

class Marigold : public Flower {
public:
    Marigold();
    ~Marigold() override = default;
    Plant* clone() override;
    std::string getDetails() override;
    double getCost() override;
    void decorate(Plant* _plant) override;
};

#endif // MARIGOLD_H