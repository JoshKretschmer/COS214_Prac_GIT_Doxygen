#include "../inc/Shrub.h"
#include <iostream>

/*!
 * @brief Constructor function for Shrub class
 *
 * Initialized type attribute, then calls Plant() constructor
 */
Shrub::Shrub() : Plant::Plant()
{
    type = "Shrub";
}