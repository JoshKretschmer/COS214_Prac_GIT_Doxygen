#ifndef FERTILIZINGSTRATEGY_H
#define FERTILIZINGSTRATEGY_H

#include "PlantCare.h"

class FertilizingStrategy : public PlantCare {
public:
    FertilizingStrategy();
    bool executeCare();
    string getCareType();
};

#endif //FERTILIZINGSTRATEGY_H
