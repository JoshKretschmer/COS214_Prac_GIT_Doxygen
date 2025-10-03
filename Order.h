/**
 * @file Order.h
 * @brief Defines the Order class for the Nursery System.
 */
#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "Plant.h"

// Forward declaration to avoid circular dependency
class Customer;

class Order {
private:
    int id;
    Customer* customer;
    std::vector<Plant> plants;

public:
    Order(int id, Customer* customer);
    void addPlant(const Plant& plant);
    void removePlant(const Plant& plant);
    double calculateTotal() const;
    int getId() const;
    void setCustomer(Customer* c) { customer = c; } // Setter for customer
    void process();
};

#endif
