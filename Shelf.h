#ifndef SHELF_H
#define SHELF_H

#include "libraries.h"
#include "Box.h"


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