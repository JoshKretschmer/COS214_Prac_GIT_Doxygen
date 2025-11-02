#include "../inc/HoneySuckle.h"
#include <cstdlib>
#include <string>
#include <iostream>

/*!
 * @brief Constructor function for HoneySuckle class
 *
 * Initializes id and price attributes, then calls Shrub() constructor
 */
HoneySuckle::HoneySuckle() : Shrub::Shrub()
{
    int randomNum = rand() % 101;
    this->id = "HS" + std::to_string(randomNum);
    this->price = 39.95;
}

/*!
 *  return string formatted as ID: [id] \n Type: [type] \n Name: Honey Suckle
 *
 * @return string containing basic details of the plant
 */
std::string HoneySuckle::getDetails()
{
    std::string det;
    det = det + "ID: " + id + "\n";
    det = det + "Type: " + type + "\n";
    det = det + "Name: Honey Suckle" + "\n";
    return det;
}

/*!
 * @return price attribute of HoneySuckle (39.95)
 */
double HoneySuckle::getCost()
{
    return this->price;
}