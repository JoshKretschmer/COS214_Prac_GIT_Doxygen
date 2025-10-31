#ifndef FERTILIZINGSTRATEGY_H
#define FERTILIZINGSTRATEGY_H

#include "PlantCare.h"

class FertilizingStrategy : public PlantCare
{
public:
    FertilizingStrategy();
    bool executeCare();
    std::string getCareType();
    virtual PlantCare *clone() const override;
};

#endif // FERTILIZINGSTRATEGY_H
