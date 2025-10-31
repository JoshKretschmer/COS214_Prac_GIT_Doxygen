#ifndef WATERINGSTRATEGY_H
#define WATERINGSTRATEGY_H

#include "PlantCare.h"

class WateringStrategy : public PlantCare
{
public:
    WateringStrategy();
    bool executeCare();
    std::string getCareType();
    virtual PlantCare *clone() const override;
};

#endif // WATERINGSTRATEGY_H
