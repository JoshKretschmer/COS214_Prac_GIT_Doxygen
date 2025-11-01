#include "../inc/ManagerCommand.h"
#include "../inc/Customer.h"
#include "../inc/Request.h"
#include <iostream>

/*!
 * @brief Constructor for ManagerCommand
 *
 * @param _request Request object to be contained
 */
ManagerCommand::ManagerCommand(Request *_request) : Command(_request)
{
    access = "manager";
}

/*!
 * @brief Destructor for ManagerCommand
 */
ManagerCommand::~ManagerCommand()
{
}

/*!
 * @brief Executes the Request inside Command
 *
 * @return nullptr
 */
Request *ManagerCommand::execute()
{

    Customer *customer = request->getSender();
    std::string plantID = request->getPlantID();
    std::string type = request->getType();

    std::cout << "MANAGER NOTICE: Customer '" << (customer ? customer->getName() : "null")
              << "' submitted a '" << type << "' request for plant ID: '" << plantID << "'\n";
    std::cout << "We have informed our manager about your request. We will hopefully be able to help out soon.\n";

    return nullptr;
}