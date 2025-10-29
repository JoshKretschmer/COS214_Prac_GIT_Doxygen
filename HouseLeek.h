#ifndef HOUSELEEK_H
#define HOUSELEEK_H

#include "Succulent.h"

class HouseLeek : public Succulent {
public:
    HouseLeek();
    ~HouseLeek() override = default;
    Plant* clone() override;
    std::string getDetails() override;
    double getCost() override;
    void decorate(Plant* _plant) override;
};

#endif // HOUSELEEK_H