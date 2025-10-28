#include "Shelf.h"

/*!
 * @brief Basic shelf constructor
 *
 * @param _shelfName Name of shelf being created
 * @param _shelfCapacity number of Boxes that can be stored in shelf
 */
Shelf::Shelf(string _shelfName, int _shelfCapacity)
{
    shelfName = _shelfName;
    shelfCapacity = _shelfCapacity;
    boxes = new vector<Box*>();
}

/*!
 * @brief Basic shelf destructor
 */
Shelf::~Shelf()
{
    // how we handle memory will depend on the flow of control of objects
}

/*!
 *
 * @return vector containing all boxes currently stored
 */
vector<Box*> Shelf::getBoxes()
{
    return *boxes; //must not that boxes still points to the vector of boxes
}

/*!
 *
 * @param _box Box object to be added to the shelf
 */
void Shelf::addBox(Box* _box)
{
    int numBoxes = boxes->size();

    if(numBoxes<shelfCapacity)
    {
        boxes->push_back(_box);
    }
    else
    {
        cout<<"\nCould not add Box to shelf. Limit reached: "<<numBoxes<<"/"<<shelfCapacity<<endl;
    }
}

/*!
 *
 * @param _boxID Specifies box to be removed and returned
 * @return Box object that has been removed, NULL if none exists
 */
Box* Shelf::removeBox(string _boxID)
{
    //ITERATOR PATTERN HERE

    Box* actualBox = NULL; //in case the box is not present in the shelf

    if(boxes)
    {
        int numBoxes = boxes->size();

        if(numBoxes>=1)
        {
            for(int i=0; i<numBoxes; i++)
            {
                if((*boxes)[i]->getBoxID() == _boxID)
                {
                    cout<<"\nBox with ID: "<<(*boxes)[i]->getBoxID()<<" removed from shelf: "<<shelfName<<endl;
                    actualBox = (*boxes)[i];
                }
            }
        }
        else
        {
            cout<<"\n"<<shelfName<<" has no boxes...\nNo box removed...\n";
        }
    }
    else
    {
        cout<<"\nThis shelf has not been structured to hold boxes...\nNo box removed...\n";
    }
    
    return actualBox;
}

/*!
 * @brief Prints out shelf information + information of all boxes stored therein
 */
void Shelf::peak()
{
    if(boxes)
    {
        int numBoxes = boxes->size();

        cout<<"\n------"<<shelfName<<"------"<<endl;

        for(int i=0; i<numBoxes; i++)
        {
            (*boxes)[i]->peak();
        } 

        cout<<"\n--------------------\n";
    }
    else
    {
        cout<<"\nThis shelf has not been structured to hold boxes...\nCannot peak shelf";
    }
}

/*!
 *
 * @return name/category of shelf
 */
string Shelf::getShelfName()
{
    return shelfName;
}