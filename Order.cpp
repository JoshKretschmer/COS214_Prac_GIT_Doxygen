#include "Order.h"
#include "Customer.h"
#include <algorithm>
#include <iostream>

Order::Order(int id, Customer* customer) : id(id), customer(customer) {}

void Order::addPlant(const Plant& plant) {
    plants.push_back(plant);
}

void Order::removePlant(const Plant& plant) {
    plants.erase(std::remove_if(plants.begin(), plants.end(),
                 [&plant](const Plant& p) { return p.getId() == plant.getId(); }),
                 plants.end());
}

double Order::calculateTotal() const {
    double total = 0.0;
    for (const auto& plant : plants) {
        total += plant.getPrice();
    }
    return total;
}

int Order::getId() const {
    return id;
}

void Order::process() {
    std::cout << "Processing order #" << id << " for customer " << customer->getName() << "\n";
    std::cout << "Order details:\n";
    for (const auto& plant : plants) {
        std::cout << " - " << plant.getDetails() << "\n";
    }
    std::cout << "Total amount: $" << calculateTotal() << "\n";
    std::cout << "Order processed successfully!\n";
}