#include "../inc/PeanutCactus.h"
#include <cstdlib> // rand()
#include <string>
#include <iostream>

/*!
 *  return string formatted as ID: [id] \n Type: [type] \n Name: Peanut Cactus
 *
 * @return string containing basic details of the plant
 */
PeanutCactus::PeanutCactus() : Succulent::Succulent()
{
    int randomNum = rand() % 101;
    this->id = "PC" + std::to_string(randomNum);
    this->price = 35.00;
}

/*!
 *  return string formatted as ID: [id] \n Type: [type] \n Name: Peanut Cactus
 *
 * @return string containing basic details of the plant
 */
std::string PeanutCactus::getDetails()
{
    std::cout << "Getting details for PeanutCactus (ID: " << id << ")\n";
    std::string det;
    det = det + "ID: " + id + "\n";
    det = det + "Type: " + type + "\n";
    det = det + "Name: Peanut Cactus" + "\n";
    return det;
}

/*!
 * @return price attribute of PeanutCactus (35.00)
 */
double PeanutCactus::getCost()
{
    std::cout << "Getting cost of PeanutCactus\n";
    return this->price;
}