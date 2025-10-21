#include "Inventory.h"
#include <algorithm>
#include <iostream>

InventoryComponent::~InventoryComponent() {

}

//##############################################################

PlantGroup::PlantGroup() {
    groupName = "";
}

PlantGroup::~PlantGroup() {
    for (auto child : children) delete child;
    children.clear();
}

void PlantGroup::add(InventoryComponent *component) {
    children.push_back(component);
}

void PlantGroup::remove(InventoryComponent *component) {
    //children.erase(remove(children.begin(), children.end(), component), children.end());
}

vector<Plant *> PlantGroup::getPlants() {
    vector<Plant*> allPlants;
    for (auto child : children) {
        vector<Plant*> childPlants = child->getPlants();
        allPlants.insert(allPlants.end(), childPlants.begin(), childPlants.end());
    }
    return allPlants;
}

void PlantGroup::movePlant(Plant *plant, string newState) {
    for (auto child : children) {
        vector<Plant*> childPlants = child->getPlants();
        if (find(childPlants.begin(), childPlants.end(), plant) != childPlants.end()) {
            child->movePlant(plant, newState);
            return;
        }
    }
}

//##############################################################

Inventory::Inventory() {
    
}

Inventory::~Inventory() {
    for (auto plant : plants) delete plant;
    for (auto state : states) delete state;
    for (auto group : groups) delete group;
}

void Inventory::addPlant(Plant *plant) {
    plants.push_back(plant);
    notifyObservers(); // Observer pattern
}

void Inventory::removePlant(string plantId) {
    for (auto it = plants.begin(); it != plants.end(); ++it) {
        if ((*it)->getDetails() == plantId) { // Simplified; ideally compare ID
            delete *it;
            plants.erase(it);
            notifyObservers();
            return;
        }
    }
}

void Inventory::updateStock(string plantType, int quantity) {
    stockLevels[plantType] = quantity;
    notifyObservers();
}

int Inventory::getStockLevel(string plantType) {
    return stockLevels[plantType];
}

InventoryIterator *Inventory::createIterator() {
    return new InventoryIterator();
}

void Inventory::notifyObservers() {
    for (auto plant : plants) plant->notify(); // Notify staff observing plants
}

void Inventory::notifyMediator(string updateType, Plant &plant) {
    cout << "Mediator notified: " << updateType << " for plant " << plant.getDetails() << endl;
}

int Inventory::getPlantCount() {
    return plants.size();
}

void Inventory::add(InventoryComponent *component) {
    groups.push_back(dynamic_cast<PlantGroup*>(component));
}

void Inventory::remove(InventoryComponent *component) {
    //groups.erase(remove(groups.begin(), groups.end(), dynamic_cast<PlantGroup*>(component)), groups.end());
}

vector<Plant *> Inventory::getPlants() {
    vector<Plant*> allPlants = plants;
    for (auto group : groups) {
        vector<Plant*> groupPlants = group->getPlants();
        allPlants.insert(allPlants.end(), groupPlants.begin(), groupPlants.end());
    }
    return allPlants;
}

void Inventory::movePlant(Plant *plant, string newState) {
    plant->movePlant(plant, newState);
    notifyObservers();
}



