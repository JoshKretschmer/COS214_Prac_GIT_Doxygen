#include "Box.h"

int Box::instanceCount = 1;

/*!
 * @brief Creator for a box object
 *
 * A box object will always contain at least one Plant object
 * Sets a creation time using Simulation time.
 *
 * @param _plant Plant object to be stored in the Box object
 */
Box::Box(Plant* _plant) //adds the plant to the box
{
    SimulationTime time;

    plant = _plant;
    timeStamp = time.getTime();
    boxId = "BOX"+to_string(instanceCount);
    instanceCount++;
}

/*!
 * Destructor for Box objects
 */
Box::~Box()
{
    instanceCount--;
    // Plant destruction will depend on how we handle it
    //Box must be destroyed by inventoryClerk
}

/*!
 * Returns a plant and removes it for the box completely
 *
 * @return Last Plant object to be added to the box
 */
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

/*!
 * @return unique ID of the Box object
 */
string Box::getBoxID()
{
    return boxId;
}

/*!
 * Prints out the Box inforamtion and details of the plants contained in the box
 */
void Box::peak()
{
    if(plant)
    {
        cout<<"\nBOX_ID: "<<boxId<<endl
            <<"TIME STAMP: "<<timeStamp<<endl
            <<plant->getDetails();
    }
    else
    {
        cout<<"\nThis box has not been structured to hold plants...\n";
    }
}