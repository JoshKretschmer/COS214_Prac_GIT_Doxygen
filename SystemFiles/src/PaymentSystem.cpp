#include "../inc/PaymentSystem.h"
#include <iostream>

/*!
 * @brief Constructs a PaymentSystem
 */
PaymentSystem::PaymentSystem()
{
    std::cout << "Calling PaymentSystem Constructor\n";
}

/*!
 * @brief Destroys the PaymentSystem
 */
PaymentSystem::~PaymentSystem()
{
    std::cout << "Calling PaymentSystem Deconstructor\n";
}

/*!
 * @brief Processes a payment for the given amount
 * @param amount The total cost to process
 * @return True if payment succeeds, false otherwise
 */
bool PaymentSystem::process(double amount)
{
    std::cout << "Calling PaymentSystem::process(amount=" << amount << ")\n";

    // Simulate payment processing (always succeed for testing)
    bool result = (amount >= 0); // Fail if amount is negative
    std::cout << "PaymentSystem::process() returning " << (result ? "true" : "false") << "\n";

    return result;
}