#include "../inc/Succulent.h"
#include <iostream>

/*!
 * @brief Constructor function for Succulent class
 *
 * Initialized type attribute, then calls Plant() constructor
 */
Succulent::Succulent() : Plant::Plant()
{
    std::cout << "Constructing a Succulent\n";
    type = "Succulent";
}