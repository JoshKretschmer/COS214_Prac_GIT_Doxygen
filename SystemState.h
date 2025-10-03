/**
 * @file SystemState.h
 * @brief Defines the SystemState class for the Nursery System.
 */
#ifndef SYSTEMSTATE_H
#define SYSTEMSTATE_H

#include "Memento.h"
#include <string>

/**
 * @class SystemState
 * @brief Manages the current state of the system and allows saving/restoring states.
 */
class SystemState {
private:
    std::string currentState;
public:
    SystemState(const std::string& state);
    Memento saveState() const;
    void restoreState(const Memento& m);
    std::string getState() const;
};

#endif
