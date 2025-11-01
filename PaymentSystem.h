#ifndef PAYMENTSYSTEM_H
#define PAYMENTSYSTEM_H

#include <string>

/*!
 * @class PaymentSystem
 * @brief Simulates a payment processing system for orders
 */
class PaymentSystem {
public:
    PaymentSystem();
    ~PaymentSystem();

    /*!
     * @brief Processes a payment for the given amount
     * @param amount The total cost to process
     * @return True if payment succeeds, false otherwise
     */
    bool process(double amount);
};

#endif // PAYMENTSYSTEM_H