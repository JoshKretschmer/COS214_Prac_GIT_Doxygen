#include "../inc/InventoryIterator.h"
#include "../inc/Inventory.h"
#include "../inc/Plant.h"
#include <iostream>

/*!
 * @brief Basic constructor function
 *
 * @param inventory Inventory object that the iterator wil work with
 */
InventoryIterator::InventoryIterator(Inventory *inventory)
    : plants(inventory->getPlants()), currentIndex(0)
{
}

/*!
 * @brief Resets the iterator object tp the start of the Inventory
 */
void InventoryIterator::first()
{
    currentIndex = 0;
}

/*!
 * @brief Steps to the next object in the Inventory
 */
void InventoryIterator::next()
{
    ++currentIndex;
}

/*!
 * @return True if the end of the Inventory has been reached, False otherwise
 */
bool InventoryIterator::hasNext()
{
    bool result = currentIndex < plants.size();
    return result;
}

/*!
 * @return Plant object the Iterator is currently pointing to, or nullptr if the end of the Inventory was reached
 */
Plant *InventoryIterator::currentItem()
{
    Plant *result = nullptr;
    if (hasNext())
    {
        result = plants[currentIndex];
    }
    else
    {
        std::cout << "InventoryIterator::currentItem() returning nullptr (end reached)\n";
    }
    return result;
}