#include "Iterator.h"

Iterator::Iterator() {}

InventoryIterator::InventoryIterator(Inventory* inventory) : plants(inventory->getPlants()), currentIndex(0) {
}

void InventoryIterator::first() {
    currentIndex = 0;
}

void InventoryIterator::next() {
    ++currentIndex;
}

bool InventoryIterator::hasNext() {
    return currentIndex < plants.size();
}

Plant* InventoryIterator::currentItem() {
    if (hasNext()) {
        return plants[currentIndex];
    } else {
        return nullptr;
    }
}