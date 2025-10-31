#include "Manager.h"
#include "Command.h"
#include "Request.h"
#include <iostream>

Manager::Manager(std::string _name) : Staff(_name) {
    staffType = "manager";
}

Manager::~Manager() = default;

void Manager::executeTask(Command* command) {
    Request* req = command->getRequest();
    
    // Manager handles ANY request that reaches it
    req->setReceiver(this);

    std::cout << "Manager " << staffName << " is now handling the request: ";
    std::cout << "Type='" << req->getType() << "', PlantID='" << req->getPlantID() << "'\n";

    Request* result = command->execute();

    if (result == nullptr) {
        std::cout << "Manager has processed the request.\n";
    }
}