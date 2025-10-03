#include "Memento.h"

Memento::Memento(const std::string& state) : state(state) {}

std::string Memento::getState() const {
    return state;
}
