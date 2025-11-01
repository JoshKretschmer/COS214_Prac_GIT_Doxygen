#include "ManagerCommand.h"
#include "Customer.h"
#include "Request.h"
#include <iostream>

/*!
 * @brief Constructor for ManagerCommand
 *
 * @param _request Request object to be contained
 */
ManagerCommand::ManagerCommand(Request *_request) : Command(_request)
{
    std::cout << "Calling ManagerCommand Constructor (request="
              << (_request ? _request->getPlantID() : "null") << ")\n";
    access = "manager";
}

/*!
 * @brief Destructor for ManagerCommand
 */
ManagerCommand::~ManagerCommand()
{
    std::cout << "Calling ManagerCommand Deconstructor\n";
}

/*!
 * @brief Executes the Request inside Command
 *
 * @return nullptr
 */
Request *ManagerCommand::execute()
{
    std::cout << "Calling ManagerCommand::execute()\n";

    Customer *customer = request->getSender();
    std::string plantID = request->getPlantID();
    std::string type = request->getType();

    std::cout << "MANAGER NOTICE: Customer '" << (customer ? customer->getName() : "null")
              << "' submitted a '" << type << "' request for plant ID: '" << plantID << "'\n";
    std::cout << "We have informed our manager about your request. We will hopefully be able to help out soon.\n";

    return nullptr;
}