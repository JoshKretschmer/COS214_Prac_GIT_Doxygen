#include "Staff.h"
#include <iostream>


Staff::Staff(const std::string& name, int id, const std::string& role)
: Person(name, id), role(role) {}


void Staff::display() const {
std::cout << "Staff: " << name << ", ID: " << id << ", Role: " << role << std::endl;
}


std::string Staff::toFileString() const {
return "Staff," + name + "," + std::to_string(id) + "," + role + "\n";
}