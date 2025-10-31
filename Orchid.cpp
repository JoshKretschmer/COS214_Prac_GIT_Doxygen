#include "Orchid.h"

/*!
 * @brief Constructor function for Orchid class
 *
 * Initializes id and price attributes, then calls Flower() constructor
 */
Orchid::Orchid() : Flower::Flower() {
    int randomNum = rand() % 101;
    this->id = "OR" + std::to_string(randomNum);

    this->price = 160.00;
}

/*!
 *  return string formatted as ID: [id] \n Type: [type] \n Name: Orchid
 *
 * @return string containing basic details of the plant
 */
std::string Orchid::getDetails() {
    std::string det;
    det = det + "ID: " + id + "\n";
    det = det + "Type: " + type + "\n";
    det = det + "Name: Orchid" + "\n";
    return det;
}

/*!
 * @return price attribute of Orchid (160.00)
 */
double Orchid::getCost() {
    return this->price;
}