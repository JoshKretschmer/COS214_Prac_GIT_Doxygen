#include "Customer.h"
#include "Order.h"
#include "Inventory.h"
#include "PlantIterator.h" 
#include "RecommendationStrategy.h"
#include "Discussion.h"
#include <iostream>

Customer::Customer(int id, const std::string& name, const std::string& email)
    : id(id), name(name), email(email), strategy(nullptr) {}

void Customer::browsePlants(Inventory* inventory) const {
    inventory->createIterator();
}

Plant Customer::requestRecommendation(Inventory* inventory) const {
    if (strategy == nullptr) {
        throw std::runtime_error("Recommendation strategy not set.");
    }
    return strategy->recommend(inventory->getPlants());
}

void Customer::placeOrder(Order& order) {
    std::cout << "Customer " << name << " is placing order #" << order.getId() << "\n";
    order.setCustomer(this); // Link this customer to the order
    order.process();
}

void Customer::joinDiscussion(Discussion* discussion) {
    discussion->addMessage(name + " joined the discussion.");
}

void Customer::setRecommendationStrategy(RecommendationStrategy* strat) {
    strategy = strat;
}

int Customer::getId() const { return id; }
std::string Customer::getName() const { return name; }
