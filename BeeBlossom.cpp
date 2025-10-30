#include "BeeBlossom.h"

/*!
 * @brief Constructor function for BeeBlossom class
 *
 * Initializes id and price attributes, then calls Shrub() constructor
 */
BeeBlossom::BeeBlossom() : Shrub::Shrub() {
    int randomNum = rand() % 101;
    this->id = "BB" + to_string(randomNum);

    this->price = 21.00;
}

/*!
 *  return string formatted as ID: [id] \n Type: [type] \n Name: Bee Blossom
 *
 * @return string containing basic details of the plant
 */
string BeeBlossom::getDetails() {
    string det;
    det = det + "ID: " + id + "\n";
    det = det + "Type: " + type + "\n";
    det = det + "Name: Bee Blossom" + "\n";
    return det;
}

/*!
 * @return price attribute of BeeBlossom (21.00)
 */
double BeeBlossom::getCost() {
    return this->price;
}