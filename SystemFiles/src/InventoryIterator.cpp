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
    std::cout << "Calling InventoryIterator Constructor (inventory size="
              << plants.size() << ")\n";
}

/*!
 * @brief Resets the iterator object tp the start of the Inventory
 */
void InventoryIterator::first()
{
    std::cout << "Calling InventoryIterator::first()\n";
    currentIndex = 0;
    std::cout << "InventoryIterator::first() - currentIndex reset to 0\n";
}

/*!
 * @brief Steps to the next object in the Inventory
 */
void InventoryIterator::next()
{
    std::cout << "Calling InventoryIterator::next() - before: currentIndex="
              << currentIndex << "\n";
    ++currentIndex;
    std::cout << "InventoryIterator::next() - after: currentIndex="
              << currentIndex << "\n";
}

/*!
 * @return True if the end of the Inventory has been reached, False otherwise
 */
bool InventoryIterator::hasNext()
{
    std::cout << "Calling InventoryIterator::hasNext() - currentIndex="
              << currentIndex << ", size=" << plants.size() << "\n";
    bool result = currentIndex < plants.size();
    std::cout << "InventoryIterator::hasNext() returning "
              << (result ? "true" : "false") << "\n";
    return result;
}

/*!
 * @return Plant object the Iterator is currently pointing to, or nullptr if the end of the Inventory was reached
 */
Plant *InventoryIterator::currentItem()
{
    std::cout << "Calling InventoryIterator::currentItem() - currentIndex="
              << currentIndex << "\n";

    Plant *result = nullptr;
    if (hasNext())
    {
        result = plants[currentIndex];
        std::cout << "InventoryIterator::currentItem() returning plant: "
                  << (result ? result->getDetails().c_str() : "null") << "\n";
    }
    else
    {
        std::cout << "InventoryIterator::currentItem() returning nullptr (end reached)\n";
    }
    return result;
}