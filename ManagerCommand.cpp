#include "ManagerCommand.h"
#include "Customer.h"
#include "Request.h"
#include <iostream>

ManagerCommand::ManagerCommand(Request *_request) : Command(_request)
{
    access = "manager";
}

ManagerCommand::~ManagerCommand() = default;

Request *ManagerCommand::execute()
{
    Customer *customer = request->getSender();
    std::string plantID = request->getPlantID();
    std::string type = request->getType();

    std::cout << "MANAGER NOTICE: Customer '" << customer->getName()
              << "' submitted a '" << type << "' request for plant ID: '" << plantID << "'\n";

    std::cout << "We have informed our manager about your request. We will hopefully be able to help out soon.\n";

    return nullptr;
}