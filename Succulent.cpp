#include "Succulent.h"

/*!
 * @brief Constructor function for Succulent class
 *
 * Initialized type attribute, then calls Plant() constructor
 */
Succulent::Succulent() : Plant::Plant() {
    type = "Succulent";
}