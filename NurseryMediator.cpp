#include "NurseryMediator.h"

void NurseryMediator::registerCustomer(Customer* c) {
    customers.push_back(c);
}

void NurseryMediator::placeOrder(Customer* c, Order* o) {
    orders.push_back(o);
    (void)c;
    (void)o;
    // TODO: Implement later
}

void NurseryMediator::facilitateDiscussion(Customer* c, Discussion* d) {
    discussions.push_back(d);
    (void)c;
    (void)d;
    // TODO: Implement later
}

std::vector<Customer*> NurseryMediator::getCustomers() const {
    return customers;
}

std::vector<Order*> NurseryMediator::getOrders() const {
    return orders;
}

std::vector<Discussion*> NurseryMediator::getDiscussions() const {
    return discussions;
}
