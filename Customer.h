#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "Plant.h"

// Forward declaration
class Order;
class RecommendationStrategy;
class Inventory;
class Discussion;

class Customer {
private:
    int id;
    std::string name;
    std::string email;
    RecommendationStrategy* strategy;

public:
    Customer(int id, const std::string& name, const std::string& email);

    void browsePlants(Inventory* inventory) const;
    Plant requestRecommendation(Inventory* inventory) const;
    void placeOrder(Order& order);
    void joinDiscussion(Discussion* discussion);

    void setRecommendationStrategy(RecommendationStrategy* strategy);

    int getId() const;
    std::string getName() const;
};

#endif
