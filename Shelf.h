#ifndef SHELF_H
#define SHELF_H

/*!
 * @headerfile Shelf.h
 */
#include "libraries.h"
#include "Box.h"

/*!
 * @class Shelf
 *
 * @brief Container class for Box objects, stored in Shelf objects in Inventory
 */
class Shelf
{
private:
    string shelfName;
    int shelfCapacity;
    vector<Box*> *boxes;
    
public:
    Shelf(string _shelfName, int _shelfCapacity);
    ~Shelf();
    void addBox(Box* _box);
    Box* removeBox(string _boxID);
    void peak();                        //see whats inside a shelf
    vector<Box*> getBoxes();
    string getShelfName();
};


#endif