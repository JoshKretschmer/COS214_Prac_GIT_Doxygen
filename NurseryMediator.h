#ifndef NURSERYMEDIATOR_H
#define NURSERYMEDIATOR_H

#include "libraries.h"
#include "Staff.h"
#include "Inventory.h"

using namespace std;

class Staff;
class Inventory;

class NurseryMediator {
    private:
        vector<Staff*> staffList; 
    public:
        NurseryMediator();
        ~NurseryMediator();
        void registerStaff(Staff* staff);
        void routeUpdate(string message, Staff* sender, Inventory* inventory);
        void notifyInventory(string updateType, Plant& plant);
};

#endif //NURSERYMEDIATOR_H