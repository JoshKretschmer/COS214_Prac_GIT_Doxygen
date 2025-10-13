#include "Inventory.h"

InventoryComponent::~InventoryComponent() {

}

//##############################################################

PlantGroup::PlantGroup() {

}

PlantGroup::~PlantGroup() {

}

void PlantGroup::add(InventoryComponent *component) {

}

void PlantGroup::remove(InventoryComponent *component) {

}

vector<Plant *> PlantGroup::getPlants() {

}

void PlantGroup::movePlant(Plant *plant, string newState) {

}

//##############################################################

Inventory::Inventory() {

}

Inventory::~Inventory() {

}

void Inventory::addPlant(Plant *plant) {

}

void Inventory::removePlant(string plantId) {

}

void Inventory::updateStock(string plantType, int quantity) {

}

int Inventory::getStockLevel(string plantType) {

}

InventoryIterator *Inventory::createIterator() {

}

void Inventory::notifyObservers() {
    
}

void Inventory::notifyMediator(string updateType, Plant &plant) {

}

int Inventory::getPlantCount() {

}

void Inventory::add(InventoryComponent *component) {

}

void Inventory::remove(InventoryComponent *component) {

}

vector<Plant *> Inventory::getPlants() {

}

void Inventory::movePlant(Plant *plant, string newState) {

}



