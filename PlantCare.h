#ifndef PLANTCARE_H
#define PLANTCARE_H

#include <string>
using namespace std;

class Plant;

class PlantCare {
public:
    PlantCare();
    ~PlantCare();
    virtual bool executeCare() = 0;
    virtual string getCareType() = 0;
};

#endif //PLANTCARE_H
