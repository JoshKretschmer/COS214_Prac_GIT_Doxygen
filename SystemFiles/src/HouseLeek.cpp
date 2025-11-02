#include "../inc/HouseLeek.h"
#include <cstdlib>
#include <string>
#include <iostream>

/*!
 * @brief Constructor function for HouseLeek class
 *
 * Initializes id and price attributes, then calls Succulent() constructor
 */
HouseLeek::HouseLeek() : Succulent::Succulent()
{
    int randomNum = rand() % 101;
    this->id = "HL" + std::to_string(randomNum);
    this->price = 35.50;
}

/*!
 *  return string formatted as ID: [id] \n Type: [type] \n Name: House Leek
 *
 * @return string containing basic details of the plant
 */
std::string HouseLeek::getDetails()
{
    std::string det;
    det = det + "ID: " + id + "\n";
    det = det + "Type: " + type + "\n";
    det = det + "Name: House Leek" + "\n";
    return det;
}

/*!
 * @return price attribute of HouseLeek (35.50)
 */
double HouseLeek::getCost()
{
    return this->price;
}