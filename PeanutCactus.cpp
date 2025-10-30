#include "PeanutCactus.h"

PeanutCactus::PeanutCactus() : Succulent::Succulent() {
    int randomNum = rand() % 101;
    this->id = "PC" + to_string(randomNum);

    this->price = 35.00;
}

/*!
 *  return string formatted as ID: [id] \n Type: [type] \n Name: Peanut Cactus
 *
 * @return string containing basic details of the plant
 */
string PeanutCactus::getDetails() {
    string det;
    det = det + "ID: " + id + "\n";
    det = det + "Type: " + type + "\n";
    det = det + "Name: Peanut Cactus" + "\n";
    return det;
}

/*!
 * @return price attribute of PeanutCactus (35.00)
 */
double PeanutCactus::getCost() {
    return this->price;
}