#ifndef WATERINGSTRATEGY_H
#define WATERINGSTRATEGY_H

#include "PlantCare.h"

class WateringStrategy : public PlantCare {
public:
    WateringStrategy() = default;
    ~WateringStrategy() override = default;
    bool executeCare() override;
    std::string getStrategyName() override;
};

#endif // WATERINGSTRATEGY_H