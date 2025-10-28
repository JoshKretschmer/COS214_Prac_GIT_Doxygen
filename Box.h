#ifndef BOX_H
#define BOX_H

/*!
 * @headerfile Box.h
 */

#include "libraries.h"
#include "Plant.h"
#include "SimulationTime.h"


/*!
 * @class Box
 *
 * @brief Container class for Plant objects
 *
 * For the purpose of more fine-grained organization of the Inventory. Plants are stores in boxes, which are kept on shelves, which exist in the inventory
 */
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