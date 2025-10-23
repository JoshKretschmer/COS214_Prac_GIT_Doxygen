#include "NurseryMediator.h"

NurseryMediator::NurseryMediator()
{
    staffList = new vector<Staff*>;
}
NurseryMediator::~NurseryMediator() {}

void NurseryMediator::registerStaff(Staff* staff) {
    if (staff) {
        staffList.push_back(staff);
        std::cout << "Mediator: Registered staff " << staff->getName() << endl;
    }
}

void NurseryMediator::routeUpdate(string message, Staff* sender, Inventory* inventory) {
    std::cout << "Mediator routing message from " << sender->getName() << ": " << message << endl;
    if (inventory) inventory->notifyObservers();
}

void NurseryMediator::notifyInventory(string updateType, Plant& plant) {
    std::cout << "Mediator notifying staff about " << updateType
              << " for plant: " << plant.getDetails() << endl;
    for (auto staff : staffList) {
        staff->updatePlantNotification(updateType, plant);
    }
}