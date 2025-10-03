/**
 * @file CareTaker.h
 * @brief Defines the CareTaker class for the Nursery System.
 */
#ifndef CARETAKER_H
#define CARETAKER_H

#include "Memento.h"
#include <vector>

/**
 * @class CareTaker
 * @brief Stores multiple mementos for the system.
 */
class CareTaker {
private:
    std::vector<Memento> mementos;

public:
    void addMemento(const Memento& memento);
    Memento getMemento(size_t index) const;
};

#endif
