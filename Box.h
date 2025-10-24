#ifndef BOX_H
#define BOX_H

#include "libraries.h"
#include "Plant.h"
#include "SimulationTime.h"

class Box
{
private:
    static int instanceCount;
    int timeStamp;
    Plant* plant;
    string boxId;
    
public:
    Box(Plant* _plant);
    ~Box();
    Plant* unboxPlant();
    string getBoxID();
    void peak();
};



#endif