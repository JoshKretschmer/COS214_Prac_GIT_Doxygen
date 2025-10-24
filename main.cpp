#include "libraries.h"
#include "Customer.h"
#include "Staff.h"
#include "SimulationTime.h"

int main(int argc, char const *argv[])
{
    SimulationTime simulationTime;
    simulationTime.initialize();
    
    delay(1);


    Inventory nursery(4);
    nursery.peak();

    Plant* p1 = new Marigold();
    Plant* p2 = new HouseLeek();

    Box* box1 = new Box(p1);

    delay(2);

    Box* box2 = new Box(p2);


    nursery.addBox(box1,"FLOWER");
    nursery.addBox(box2,"SUCCULENT");
    nursery.peak();
    
    return 0;
}
