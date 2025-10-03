/**
 * @file Plant.h
 * @brief Defines the Plant class for the Nursery System.
 */
#ifndef PLANT_H
#define PLANT_H

#include <string>

/**
 * @class Plant
 * @brief Represents a plant in the nursery.
 */
class Plant {
private:
    int id;
    std::string name;
    std::string category;
    double price;

public:
    Plant(int id, const std::string& name, const std::string& category, double price);
    int getId() const;
    std::string getName() const;
    std::string getCategory() const;
    double getPrice() const;
    std::string getDetails() const;
};

#endif
