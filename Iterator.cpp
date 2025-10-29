#include "Iterator.h"
#include "Inventory.h"
#include "Shelf.h"
#include "Box.h"

InventoryIterator::InventoryIterator(Inventory* inv)
    : inventory(inv), shelfIndex(0), boxIndex(0) {}

bool InventoryIterator::hasNext() {
    Shelf** shelves = inventory->getShelves();
    if (!shelves) return false;

    while (shelfIndex < 3) { // assuming fixed 3 shelves
        std::vector<Box*> boxes = shelves[shelfIndex]->getBoxes();
        if (boxIndex < static_cast<int>(boxes.size())) {
            return true;
        } else {
            shelfIndex++;
            boxIndex = 0;
        }
    }
    return false;
}

Plant* InventoryIterator::next() {
    Shelf** shelves = inventory->getShelves();
    if (!shelves) return nullptr;

    while (shelfIndex < 3) {
        std::vector<Box*> boxes = shelves[shelfIndex]->getBoxes();

        while (boxIndex < static_cast<int>(boxes.size())) {
            Box* box = boxes[boxIndex++];
            if (box) {
                Plant* plant = box->getPlant();
                if (plant) {
                    return plant;
                }
            }
        }
        shelfIndex++;
        boxIndex = 0;
    }

    return nullptr;
}


void InventoryIterator::reset(){
    shelfIndex = 0;
    boxIndex = 0;
}

