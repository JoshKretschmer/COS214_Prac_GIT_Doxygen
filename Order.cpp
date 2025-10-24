#include "Order.h"
#include <iostream>

using namespace std;

/**
 * @brief Constructs an empty order and initializes history tracking.
 */
Order::Order() {
    totalCost = 0.0;
    currIndex = -1;
}

/**
 * @brief Cleans up dynamically allocated plants and mementos.
 */
Order::~Order() {
    for (auto plant : plants) {
        delete plant;
    }

    for (auto* m : history){
        delete m;
    }
    history.clear();
}

/**
 * @brief Adds a plant and creates a Memento snapshot.
 */
void Order::addPlant(Plant *plant) {
    if (!plant) return;

    // Remove future states if adding after undo
    if (currIndex < (int)history.size() - 1) {
        for (int i = currIndex + 1; i < (int)history.size(); i++)
            delete history[i];
        history.erase(history.begin() + currIndex + 1, history.end());
    }

    history.push_back(createMemento());
    currIndex = history.size() - 1;

    plants.push_back(plant);
    updateCost();
}

/**
 * @brief Creates a snapshot of the current order state.
 */
Memento *Order::createMemento() {
    return new Memento(plants, totalCost);
}

/**
 * @brief Returns the history vector of mementos.
 */
vector<Memento*>& Order::getMementos() {
    return history;
}

/**
 * @brief Restores the order to a previous Memento state.
 */
void Order::restoreMemento(Memento *memento) {
    if (!memento) return;

    for (auto* plant : plants) {
        delete plant;
    }
    plants.clear();

    for (auto* saved : memento->getSavedPlants()) {
        plants.push_back(saved->clone());
    }

    totalCost = memento->getSavedCost();
    cout << "Order restored. Current total cost: " << totalCost << endl;
}

/**
 * @brief Returns a formatted string with order details.
 */
string Order::getDetails() {
    string details = "Order ID: " + orderId + "\nPlants:\n";
    for (auto plant : plants) {
        details += "- " + plant->getDetails() + "\n";
    }
    details += "Total cost: " + to_string(totalCost);
    return details;
}

/**
 * @brief Recalculates total cost of the order.
 */
void Order::updateCost() {
    totalCost = 0.0;
    for (auto plant : plants) {
        totalCost += plant->getCost();
    }
}

/**
 * @brief Undo the last addition of a plant.
 */
void Order::undoLastAddition() {
    if (currIndex <= 0) {
        cout << "Nothing to undo.\n";
        return;
    }

    currIndex--;
    restoreMemento(history[currIndex]);
    cout << "Undo successful.\n";
}

/**
 * @brief Redo the last undone addition of a plant.
 */
void Order::redoLastAddition() {
    if (currIndex >= (int)history.size() - 1) {
        cout << "Nothing to redo.\n";
        return;
    }

    currIndex++;
    restoreMemento(history[currIndex]);
    cout << "Redo successful.\n";
}
