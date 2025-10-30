#include "PlantGroup.h"
#include "InventoryComponent.h"
#include "Plant.h"

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