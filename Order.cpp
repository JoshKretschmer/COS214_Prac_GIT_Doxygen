#include "Order.h"
#include <iostream>

using namespace std;

/*!
 * @brief Basic constructor function
 */
Order::Order() {
    totalCost = 0.0;
}

/*!
 * @brief Basic destructor function
 */
Order::~Order() {
    for (auto plant : plants) {
        delete plant;
    }
    for (auto m : mementos) {
        delete m;
    }
    mementos.clear();
    for (auto m : redoMementos) {
        delete m;
    }
    redoMementos.clear();
}

/*!
 * @brief Creates a Memento of the object state, then adds the Plant to the Order object
 *
 * @param plant Plant to be added to the Order
 */
void Order::addPlant(Plant *plant) {
    mementos.push_back(createMemento()); // Save state before change

    plants.push_back(plant);
    updateCost();
}

/*!
 * @return new Memento object containing the current Object state
 */
Memento *Order::createMemento() {
    vector<Plant*> plantClones;
    plantClones.reserve(plants.size());

    for (auto plant : plants) {
        plantClones.push_back(plant->clone());
    }
    return new Memento(plantClones, totalCost);
}

/*!
 *
 * @return All stored previous states of the object
 */
vector<Memento*>& Order::getMementos() {
    return mementos; 
}

/*!
 *
 * @return All stored redo states of the object
 */
vector<Memento*>& Order::getRedoMementos() {
    return redoMementos; 
}

/*!
 * @brief Restores the Object to a previous state
 *
 * @param memento Contains previous state to be restored
 */
void Order::restoreMemento(Memento *memento) {
    if (!memento) {
        return;
    }
    for (auto* p : plants)
        delete p;
    plants.clear();

    for (auto* saved : memento->getSavedPlants()){
        plants.push_back(saved->clone());
    }

    totalCost = memento->getSavedCost();
    cout << "Order restored. Current total cost: " << totalCost << endl;
}

/*!
 * @brief Return a string containing the Order ID, details of all plants in the order, and the total cost of these plants
 *
 * @return Details of Order
 */
string Order::getDetails() {
    string details = "Order ID: " + orderId + "\nPlants:\n";
    for (auto plant : plants) {
        details += "- " + plant->getDetails() + "\n";
    }
    details += "Total cost: " + to_string(totalCost);
    return details;
}

/*!
 * @brief Updates the total order cost
 */
void Order::updateCost() {
    totalCost = 0.0;
    for (auto plant : plants) {
        totalCost += plant->getCost();
    }
}

/*!
 * @brief undo last action done on the Object
 */
void Order::undoLastAddition() {
    if (mementos.empty()) return;

    Memento* last = mementos.back();
    mementos.pop_back();

    redoMementos.push_back(createMemento()); // Save current state for redo

    restoreMemento(last);
    delete last;
}

/*!
 * @brief redo last undone action on the Object
 */
void Order::redoLastStep() {
    if (redoMementos.empty()) return;

    Memento* next = redoMementos.back();
    redoMementos.pop_back();

    mementos.push_back(createMemento()); // Save current state for undo

    restoreMemento(next);
    delete next;
}

/*!
 * @return Copy of the plants in the order
 */
vector<Plant*> Order::getPlants() const {
    return plants;
}

/*!
 * @return Pointer to the last plant in the order (or nullptr if empty)
 */
Plant* Order::getLastPlant() {
    if (plants.empty()) return nullptr;
    return plants.back();
}

/*!
 * @brief Replace the last plant in the order with a new one (e.g., decorated)
 */
void Order::replaceLastPlant(Plant* newPlant) {
    if (plants.empty()) return;
    delete plants.back();
    plants.back() = newPlant;
    updateCost();
}