#include "Memento.h"

Memento::Memento(const vector<Plant*>& plants, double cost) {
    savedCost = cost;
    // Deep copy plants to avoid external modification
    for (auto plant : plants) {
        savedPlants.push_back(plant->clone()); 
    }
}

Memento::~Memento() {
    // Cleanup if necessary
    for (auto plant : savedPlants) {
        delete plant; // Assuming Plant is dynamically allocated
    }
    savedCost = 0;
}

const vector<Plant*>& Memento::getSavedPlants() const {
    return savedPlants;
}

double Memento::getSavedCost() const {
    return savedCost;
}

