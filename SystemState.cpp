#include "SystemState.h"

SystemState::SystemState(const std::string& state) : currentState(state) {}

Memento SystemState::saveState() const {
    return Memento(currentState);
}

void SystemState::restoreState(const Memento& m) {
    currentState = m.getState();
}

std::string SystemState::getState() const {
    return currentState;
}
