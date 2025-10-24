#include "Box.h"

int Box::instanceCount = 0;

Box::Box(Plant* _plant) //adds the plant to the box
{
    SimulationTime time;

    plant = _plant;
    timeStamp = time.getTime();
    boxId = "BOX"+to_string(instanceCount);
    instanceCount++;
}

Box::~Box()
{
    instanceCount--;
    // Plant destruction will depend on how we handle it
    //Box must be destroyed by inventoryClerk
}

Plant* Box::unboxPlant()
{
    Plant* holder;
    holder = NULL;

    if(plant)
    {
        holder = plant;
        plant = NULL;
    }
    
    return holder;
}

string Box::getBoxID()
{
    return boxId;
}

void Box::peak()
{
    if(plant)
    {
        cout<<"\nBOX_ID: "<<boxId<<endl
            <<"TIME STAMP: "<<timeStamp<<endl
            <<"PLANT_ID: "<<plant->getID()<<endl;
    }
    else
    {
        cout<<"\nThis box has not been structured to hold plants...\n";
    }
}