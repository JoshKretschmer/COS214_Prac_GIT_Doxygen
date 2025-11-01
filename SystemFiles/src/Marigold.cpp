#include "../inc/Marigold.h"
#include <cstdlib>
#include <string>
#include <iostream>

/*!
 * @brief Constructor function for Marigold class
 *
 * Initializes id and price attributes, then calls Flower() constructor
 */
Marigold::Marigold() : Flower::Flower()
{
    int randomNum = rand() % 101;
    this->id = "MG" + std::to_string(randomNum);
    this->price = 16.00;
}

/*!
 *  return string formatted as ID: [id] \n Type: [type] \n Name: Marigold
 *
 * @return string containing basic details of the plant
 */
std::string Marigold::getDetails()
{
    std::string det;
    det = det + "ID: " + id + "\n";
    det = det + "Type: " + type + "\n";
    det = det + "Name: Marigold" + "\n";
    return det;
}

/*!
 * @return price attribute of Marigold (16.00)
 */
double Marigold::getCost()
{
    return this->price;
}