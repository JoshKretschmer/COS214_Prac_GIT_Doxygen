#include "Inventory.h"

/*!
 * @brief Creator function for Inventory
 *
 * Creates a set number of Shelf objects with a variable capacity for Box objects that contain Plants
 *
 * @param _shelfCapacity Specifies the amount Box objects to be stored in each Shelf(Category)
 */
Inventory::Inventory(int _shelfCapacity)
{
    shelves = new Shelf *[3];

    shelves[0] = new Shelf("FLOWER", _shelfCapacity);
    shelves[1] = new Shelf("SHRUB", _shelfCapacity);
    shelves[2] = new Shelf("SUCCULENT", _shelfCapacity);
}

/*!
 * @brief Basic destructor for Inventory
 */
Inventory::~Inventory()
{
    // yet to implement destructor. First validate the control of object flow
}

/*!
 * @brief Function to add objects to the inventory
 *
 * @param _box Box object containing Plants
 * @param _shelfName Specifies the Shelf/Category that the Box is stored in
 */
void Inventory::addBox(Box *_box, string _shelfName)
{
    for (int i = 0; i < 3; i++)
    {
        if (shelves[i]->getShelfName() == _shelfName)
        {
            shelves[i]->addBox(_box);
        }
    }
}

/*!
 *
 * @param _boxID Box object to be removed
 * @param _shelfName Category that Box object is stored in
 * @return Box object found , or NULL if no such box exists
 */
Box *Inventory::removeBox(string _boxID, string _shelfName)
{
    Box* actualBox = NULL;

    for (int i = 0; i < 3; i++)
    {
        if (shelves[i]->getShelfName() == _shelfName)
        {
            actualBox = shelves[i]->removeBox(_boxID);
        }
    }

    return actualBox;
}

/*!
 * @brief Prints out the contents of each Shelf (contents of Boxes stored in Shelves)
 */
void Inventory::peak()
{
    for (int i=0; i<3; i++)
    {
        shelves[i]->peak();
    }
}
