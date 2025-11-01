#include "SalesCommand.h"
#include <iostream>
#include "Customer.h"
#include "Request.h"
#include "Staff.h"

/*!
 * @brief Basic constructor function
 *
 * @param _request Request object to be contained
 */
SalesCommand::SalesCommand(Request *_request) : Command(_request)
{
    std::cout << "Calling SalesCommand Constructor (request="
              << (_request ? _request->getPlantID() : "null") << ")\n";
    access = "sales";
    std::cout << "SalesCommand Constructor set access to \"sales\"\n";
}

/*!
 * @brief Basic destructor function
 */
SalesCommand::~SalesCommand()
{
    std::cout << "Calling SalesCommand Deconstructor\n";
}

/*!
 * @brief Executes the Request inside Command (add Plant to Order)
 *
 * @return nullptr
 */
Request *SalesCommand::execute()
{
    std::cout << "Calling SalesCommand::execute()\n";

    Customer *customer = request->getSender();
    std::string plantID = request->getPlantID();
    std::string decor = request->getExtra();

    std::cout << "SalesCommand::execute() adding plantID=\"" << plantID
              << "\" with decor=\"" << decor << "\" for customer="
              << (customer ? customer->getName() : "null") << "\n";

    customer->addPlant(plantID, decor);

    std::cout << (request->getReceiver() ? request->getReceiver()->getStaffName() : "null")
              << " has added " << plantID << " to your order.\n";

    std::cout << "SalesCommand::execute() returning nullptr\n";
    return nullptr;
}