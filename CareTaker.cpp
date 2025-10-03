#include "CareTaker.h"
#include <stdexcept>

void CareTaker::addMemento(const Memento& memento) {
    mementos.push_back(memento);
}

Memento CareTaker::getMemento(size_t index) const {
    if (index >= mementos.size()) {
        throw std::out_of_range("Invalid memento index.");
    }
    return mementos[index];
}
