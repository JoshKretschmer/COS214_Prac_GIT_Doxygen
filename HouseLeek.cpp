#include "HouseLeek.h"
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
    std::cout << "Constructing HouseLeek\n";
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
    std::cout << "Getting details for HouseLeek (ID: " << id << ")\n";
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
    std::cout << "Getting cost of HouseLeek\n";
    return this->price;
}