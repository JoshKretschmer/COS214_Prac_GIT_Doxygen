#ifndef WATERINGSTRATEGY_H
#define WATERINGSTRATEGY_H

#include "PlantCare.h"

class WateringStrategy : public PlantCare {
public:
    WateringStrategy();
    bool executeCare();
    string getCareType();
};

#endif //WATERINGSTRATEGY_H
