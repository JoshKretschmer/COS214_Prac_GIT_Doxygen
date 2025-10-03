#ifndef STAFF_H
#define STAFF_H


#include "Person.h"
#include <string>


class Staff : public Person {
std::string role;
public:
Staff(const std::string& name, int id, const std::string& role);
void display() const override;
std::string toFileString() const override;
};


#endif