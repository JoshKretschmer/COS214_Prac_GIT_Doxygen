#include "Order.h"
#include <iostream>

using namespace std;

Order::Order() {
    totalCost = 0.0;
}

Order::~Order() {
    for (auto plant : plants) {
        delete plant;
    }
}

void Order::addPlant(Plant *plant) {
    mementos.push_back(createMemento()); // Save state before change
    plants.push_back(plant);
    updateCost();
}

Memento *Order::createMemento() {
    return new Memento(plants, totalCost);
}

 vector<Memento*>& Order::getMementos() {
    return mementos; 
}

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

string Order::getDetails() {
    string details = "Order ID: " + orderId + "\nPlants:\n";
    for (auto plant : plants) {
        details += "- " + plant->getDetails() + "\n";
    }
    details += "Total cost: " + to_string(totalCost);
    return details;
}

void Order::updateCost() {
    totalCost = 0.0;
    for (auto plant : plants) {
        totalCost += plant->getCost();
    }
}

void Order::undoLastAddition() {
    if (mementos.empty()) return;

    Memento* last = mementos.back();
    mementos.pop_back();

    for (auto* p : plants)
        delete p;
    plants.clear();

    for (auto* saved : last->getSavedPlants())
        plants.push_back(saved->clone());

    totalCost = last->getSavedCost();

    std::cout << "Order restored. Current total cost: " << totalCost << std::endl;
    delete last;
}



