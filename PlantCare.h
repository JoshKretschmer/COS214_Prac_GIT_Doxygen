#ifndef PLANTCARE_H
#define PLANTCARE_H

#include <string>
using namespace std;

class Plant;

class PlantCare {
public:
    PlantCare();
    virtual ~PlantCare();
    virtual bool executeCare();
    virtual string getCareType();
};

class SunlightStrategy : public PlantCare {
public:
    SunlightStrategy();
    ~SunlightStrategy() override;
    bool executeCare();
    string getCareType();
};

class WateringStrategy : public PlantCare {
public:
    WateringStrategy();
    ~WateringStrategy() override;
    bool executeCare();
    string getCareType();
};

class FertilizingStrategy : public PlantCare {
public:
    FertilizingStrategy();
    ~FertilizingStrategy() override;
    bool executeCare();
    string getCareType();
};

class CompositeCareStrategy : public PlantCare {
public:
    CompositeCareStrategy();
    ~CompositeCareStrategy() override;
    bool executeCare();
    string getCareType();
};



#endif //PLANTCARE_H
