#include "Iterator.h"

/*!
 * @brief Abstract class constructor
 */
Iterator::Iterator() {

}

/*!
 * @brief Abstract class destructor
 */
Iterator::~Iterator() {

}

//######################################################

/*!
 * @brief Basic constructor function
 *
 * @param inventory Inventory object on which the iterator will run
 */
InventoryIterator::InventoryIterator(Inventory* inventory) : inventory(inventory) {
    currentIndex = 0;
}

/*!
 *
 * @return True if end of Inventory has not been reached, false if otherwise
 */
bool InventoryIterator::hasNext() {
    if (currentIndex < inventory->getPlantCount()) {
        return true;
    }
    return false;
}

/*!
 * @brief Moves the iterator pointer to the next object in the list and returns
 *
 * @return next Plant object present in the Inventory
 */
Plant* InventoryIterator::next() {
    if (hasNext()) {
        return inventory->getPlants()[currentIndex++];
    }
    return nullptr;
}

