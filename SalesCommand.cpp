#include "SalesCommand.h"
#include <iostream>
#include "Customer.h"
#include "Request.h"

/*!
 * @brief Basic constructor function
 *
 * @param _request Request object to be contained
 */
SalesCommand::SalesCommand(Request *_request) : Command(_request)
{
    access = "sales";
}

/*!
 * @brief Basic destructor function
 */
SalesCommand::~SalesCommand()
{
}

/*!
 * @brief Executes the Request inside Command (add Plant to Order)
 *
 * @return nullptr
 */
Request *SalesCommand::execute()
{
    Customer *customer = request->getSender();
    // all I want to do is add the plant to the customer's current order
    std::string plantID = request->getPlantID();
    std::string decor = request->getExtra();
    customer->addPlant(plantID, decor); // note that we need to add functionality to this
    std::cout << request->getReceiver() << " has added " << plantID << " to your order.\n";

    return nullptr;
}