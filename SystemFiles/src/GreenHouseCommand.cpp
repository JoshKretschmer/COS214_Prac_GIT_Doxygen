#include "../inc/GreenHouseCommand.h"
#include "../inc/Request.h"
#include <iostream>

/*!
 * @brief Basic constructor function
 *
 * @param _request Request object to be contained
 */
GreenHouseCommand::GreenHouseCommand(Request *_request) : Command(_request)
{
    access = "greenhouse";
}

/*!
 * @brief Basic destructor function
 */
GreenHouseCommand::~GreenHouseCommand()
{

}

/*!
 * @brief Executes the Request inside Command (nurturing Plant)
 *
 * @return nullptr
 */
Request *GreenHouseCommand::execute()
{
    std::cout << "Calling GreenHouseCommand::execute()\n";

    Staff *receiver = request->getReceiver();
    Horticulturist *horticulturist = dynamic_cast<Horticulturist *>(receiver);

    std::cout << (horticulturist ? horticulturist->getStaffName() : "null")
              << " is now tending to: " << request->getPlantID() << "\n";

    return nullptr;
}