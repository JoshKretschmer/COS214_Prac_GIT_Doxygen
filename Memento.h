/**
 * @file Memento.h
 * @brief Defines the Memento class for the Nursery System.
 */
#ifndef MEMENTO_H
#define MEMENTO_H

#include <string>

/**
 * @class Memento
 * @brief Stores the state of the system.
 */
class Memento {
private:
    std::string state;
public:
    Memento(const std::string& state);
    std::string getState() const;
};

#endif
