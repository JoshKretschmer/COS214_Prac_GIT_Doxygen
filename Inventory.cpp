#include "Inventory.h"
#include <algorithm>
#include <iostream>

InventoryComponent::InventoryComponent() {}

InventoryComponent::~InventoryComponent() {
}

PlantGroup::PlantGroup(string name) : InventoryComponent(), groupName(name) {}

PlantGroup::~PlantGroup() {
    for (auto c : children) {
        delete c;
    }
    children.clear();
}

void PlantGroup::add(InventoryComponent* component) {
    if (!component)
        return;
    children.push_back(component);
}

void PlantGroup::remove(InventoryComponent* component) {
    auto it = std::find(children.begin(), children.end(), component);
    if (it != children.end()) {
        if (*it == component)
            delete *it;
        children.erase(it);
    }
}

vector<Plant*> PlantGroup::getPlants() {
    vector<Plant*> result;
    for (auto c : children) {
        auto cPlants = c->getPlants();
        result.insert(result.end(), cPlants.begin(), cPlants.end());
    }
    return result;
}

void PlantGroup::movePlant(Plant* plant, string newState) {
    for (auto c : children) {
        c->movePlant(plant, newState);
    }
    
}

Inventory::Inventory() : InventoryComponent() {}

Inventory::~Inventory() {
    for (auto p : plants) {
        delete p;
    }
    plants.clear();

    for (auto g : groups) {
        delete g;
    }
    groups.clear();
}

void Inventory::addPlant(Plant* plant) {
    plants.push_back(plant);
}

void Inventory::removePlant(string plantId) {
    for (auto it = plants.begin(); it != plants.end(); ++it) {
        if ((*it)->getDetails() == plantId) {
            Plant* removed = *it;
            plants.erase(it);
            delete removed; // free memory
            break;
        }
    }
}

void Inventory::updateStock(string plantType, int quantity) {
    stockLevels[plantType] = quantity;
}

int Inventory::getStockLevel(string plantType) {
    return stockLevels[plantType];
}

InventoryIterator* Inventory::createIterator() {
    return new InventoryIterator(this);
}

// void Inventory::notifyObservers() {
//     // can notify Observer pattern if implemented
// }

int Inventory::getPlantCount() {
    return plants.size();
}

void Inventory::add(InventoryComponent* component) {
    groups.push_back(dynamic_cast<PlantGroup*>(component));
}

void Inventory::remove(InventoryComponent* component) {
    auto it = std::find(groups.begin(), groups.end(), dynamic_cast<PlantGroup*>(component));
    if (it != groups.end()) {
        if (*it == component) delete *it;
        groups.erase(it);
    }
}

vector<Plant*> Inventory::getPlants() {
    vector<Plant*> allPlants = plants;
    for (auto g : groups) {
        auto gPlants = g->getPlants();
        allPlants.insert(allPlants.end(), gPlants.begin(), gPlants.end());
    }
    return allPlants;
}

void Inventory::movePlant(Plant* plant, string newState) {
    if (std::find(plants.begin(), plants.end(), plant) != plants.end()) {
        return ;// plant is in main inventory
    }

    for (auto g : groups) {
        g->movePlant(plant, newState);
    }
}