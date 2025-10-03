#include "Plant.h"

Plant::Plant(int id, const std::string& name, const std::string& category, double price)
    : id(id), name(name), category(category), price(price) {}

int Plant::getId() const { return id; }
std::string Plant::getName() const { return name; }
std::string Plant::getCategory() const { return category; }
double Plant::getPrice() const { return price; }

std::string Plant::getDetails() const {
    return "Plant[ID: " + std::to_string(id) + ", Name: " + name +
           ", Category: " + category + ", Price: $" + std::to_string(price) + "]";
}
