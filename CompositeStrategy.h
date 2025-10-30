#ifndef COMPOSITESTRATEGY_H
#define COMPOSITESTRATEGY_H

#include "PlantCare.h"

class CompositeCareStrategy : public PlantCare {
public:
    CompositeCareStrategy();
    bool executeCare();
    string getCareType();
};

#endif //COMPOSITESTRATEGY_H
