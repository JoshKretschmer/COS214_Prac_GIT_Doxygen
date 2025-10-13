#ifndef NURSERYMEDIATOR_H
#define NURSERYMEDIATOR_H

#include "Staff.h"
#include "Inventory.h"
#include <string>
using namespace std;

class NurseryMediator {
    public:
        NurseryMediator();
        ~NurseryMediator();
        void registerStaff(Staff* staff);
        void routeUpdate(string message, Staff* sender, Inventory& inventory);
        void notifyInventory(string updateType, Plant& plant);
};

#endif //NURSERYMEDIATOR_H
