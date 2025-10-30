#include "Flower.h"

/*!
 * @brief Constructor function for Flower class
 *
 * Initialized type attribute, then calls Plant() constructor
 */
Flower::Flower() : Plant::Plant() {
    type = "Flower";
}