#include "InventoryIterator.h"
#include "Inventory.h"


/*!
 * @brief Basic constructor function
 *
 * @param inventory Inventory object that the iterator wil work with
 */
InventoryIterator::InventoryIterator(Inventory* inventory) : plants(inventory->getPlants()), currentIndex(0) {
}

/*!
 * @brief Resets the iterator object tp the start of the Inventory
 */
void InventoryIterator::first() {
    currentIndex = 0;
}

/*!
 * @brief Steps to the next object in the Inventory
 */
void InventoryIterator::next() {
    ++currentIndex;
}

/*!
 * @return True if the end of the Inventory has been reached, False otherwise
 */
bool InventoryIterator::hasNext() {
    return currentIndex < plants.size();
}

/*!
 * @return Plant object the Iterator is currently pointing to, or nullptr if the end of the Inventory was reached
 */
Plant* InventoryIterator::currentItem() {
    if (hasNext()) {
        return plants[currentIndex];
    } else {
        return nullptr;
    }
}