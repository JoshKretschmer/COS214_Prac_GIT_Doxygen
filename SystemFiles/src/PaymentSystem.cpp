#include "../inc/PaymentSystem.h"
#include <iostream>

/*!
 * @brief Constructs a PaymentSystem
 */
PaymentSystem::PaymentSystem()
{
}

/*!
 * @brief Destroys the PaymentSystem
 */
PaymentSystem::~PaymentSystem()
{
}

/*!
 * @brief Processes a payment for the given amount
 * @param amount The total cost to process
 * @return True if payment succeeds, false otherwise
 */
bool PaymentSystem::process(double amount)
{
    // Simulate payment processing (always succeed for testing)
    bool result = (amount >= 0); // Fail if amount is negative

    return result;
}