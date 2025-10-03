/**
 * @file NurseryMediator.h
 * @brief Defines the NurseryMediator class for coordinating the nursery system.
 */
#ifndef NURSERYMEDIATOR_H
#define NURSERYMEDIATOR_H

#include <vector>
#include <string>
#include "Customer.h"
#include "Order.h"
#include "Discussion.h"

/**
 * @class NurseryMediator
 * @brief Mediates interactions between customers, orders, and discussions.
 */
class NurseryMediator {
private:
    std::vector<Customer*> customers;
    std::vector<Order*> orders;
    std::vector<Discussion*> discussions;

public:
    void registerCustomer(Customer* c);
    void placeOrder(Customer* c, Order* o);
    void facilitateDiscussion(Customer* c, Discussion* d);
    std::vector<Customer*> getCustomers() const;
    std::vector<Order*> getOrders() const;
    std::vector<Discussion*> getDiscussions() const;
};

#endif
