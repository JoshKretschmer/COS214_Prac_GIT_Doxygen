#include "BeeBlossom.h"
#include <cstdlib>
#include <string>
#include <iostream>

/*!
 * @brief Constructor function for BeeBlossom class
 *
 * Initializes id and price attributes, then calls Shrub() constructor
 */
BeeBlossom::BeeBlossom() : Shrub::Shrub()
{
    std::cout << "Constructing BeeBlossom\n";
    int randomNum = rand() % 101;
    this->id = "BB" + std::to_string(randomNum);
    this->price = 21.00;
}

/*!
 *  return string formatted as ID: [id] \n Type: [type] \n Name: Bee Blossom
 *
 * @return string containing basic details of the plant
 */
std::string BeeBlossom::getDetails()
{
    std::cout << "Getting details for BeeBlossom (ID: " << id << ")\n";
    std::string det;
    det = det + "ID: " + id + "\n";
    det = det + "Type: " + type + "\n";
    det = det + "Name: Bee Blossom" + "\n";
    return det;
}

/*!
 * @return price attribute of BeeBlossom (21.00)
 */
double BeeBlossom::getCost()
{
    std::cout << "Getting cost of BeeBlossom\n";
    return this->price;
}