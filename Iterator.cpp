#include "Iterator.h"

Iterator::Iterator() {

}

Iterator::~Iterator() {

}

bool Iterator::hasNext() {
    return false;
}

Plant* Iterator::next() {
    return nullptr;
}

//######################################################

InventoryIterator::InventoryIterator(Inventory* inventory) : inventory(inventory) {
    currentIndex = 0;
}

bool InventoryIterator::hasNext() {
    if (currentIndex < inventory->getPlantCount()) {
        return true;
    }
    return false;
}

Plant* InventoryIterator::next() {
    if (hasNext()) {
        return inventory->getPlants()[currentIndex++];
    }
    return nullptr;
}

