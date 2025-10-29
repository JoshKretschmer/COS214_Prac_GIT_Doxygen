#ifndef FERTILIZINGSTRATEGY_H
#define FERTILIZINGSTRATEGY_H

#include "PlantCare.h"

class FertilizingStrategy : public PlantCare {
public:
    FertilizingStrategy() = default;
    ~FertilizingStrategy() override = default;
    bool executeCare() override;
    std::string getStrategyName() override;
};

#endif // FERTILIZINGSTRATEGY_H