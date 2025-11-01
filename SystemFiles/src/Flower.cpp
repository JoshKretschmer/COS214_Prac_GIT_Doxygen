#include "../inc/Flower.h"
#include <iostream>

/*!
 * @brief Constructor function for Flower class
 *
 * Initialized type attribute, then calls Plant() constructor
 */
Flower::Flower() : Plant::Plant()
{
    std::cout << "Constructing a Flower\n";
    type = "Flower";
}